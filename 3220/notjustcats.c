#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "notjustcats.h"

int fileCount;

int main(int argc, char *argv[]) {
    char *imageFile = NULL;
    char *outputDir = NULL;
    if (argc > 2) {
        outputDir = argv[2];
        imageFile = argv[1];
    } else if (argc == 2) {
        outputDir = "./recovered_files";
        imageFile = argv[1];
    } else {
        fprintf(stderr, "Error, invalid command arguments \n");
        exit(1);
    }
    /* Makes directory with given path + mode*/
    mkdir(outputDir, ACCESSPERMS);
    int file = open(imageFile, O_RDONLY);
    struct stat fileInformation;

    /* Grabs information about a file, if its less than 0 then something went wrong */
    if (fstat(file, &fileInformation) < 0) {
        perror("Error, unable to get file size \n");
    }
    /* Ask OS for chunk of memory with read + write and that is not shared*/
    char *floppy = mmap(NULL, fileInformation.st_size, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE, file, 0);

    fileCount = 0;
    char *path = malloc(STRING_BUFFER);
    readWriteDirectory(floppy, ROOT, path, outputDir);

    /* Close file + free memory */
    close(file);
    free(path);
    munmap(floppy, fileInformation.st_size);
    return 0;
}

/* Reads through the image file metadata about directories and writes in outputDir */
void readWriteDirectory(char *image, int startSector, char *path, char *outputDir) {
    int offset = startSector * SECTOR_SIZES;
    for (int i = offset; image[i] != '\0'; i += DIRECTORY_ENTRY_SIZE) {

        /* FILENAME_LENGTH + 1 accounts for null character */
        char *fileName = (char *) malloc(FILE_NAME_LENGTH + 1);
        strncpy(fileName, &image[i + FILE_NAME_OFFSET], FILE_NAME_LENGTH);
        char *trimName = (char *) malloc(FILE_NAME_LENGTH + 1);
        fileName[FILE_NAME_LENGTH] = '\0';

        reduceFileName(trimName, fileName);
        /* if the directory contains a "." or ".." skip */
        if (strcmp(trimName, ".") == 0 || strcmp(trimName, "..") == 0) {
            continue;
        }
        char *name = (char *) malloc(STRING_BUFFER);
        strcpy(name, "/");
        strcat(name, trimName);

        /* +1 for null character */
        char *extension = (char *) malloc(EXT_LENGTH + 1);
        strncpy(extension, &image[i + EXT_OFFSET], EXT_LENGTH);
        extension[EXT_LENGTH] = '\0';

        uint8_t attribute = *(uint8_t *) (image + i + ATTR_OFFSET);
        bool isDir = ((attribute & DIRECTORY) == DIRECTORY);

        uint32_t size = *(uint32_t *) (image + i + FILE_SIZE_OFFSET);
        uint16_t cluster = (uint16_t) image[i + FIRST_CLUSTER_OFFSET];


        if (!isDir) {
            if (image[i] == DELETED) {
                printf("FILE\tDELETED\t%s%s.%s\t%d\n", path, name, extension, size);
            } else {
                printf("FILE\tNORMAL\t%s%s.%s\t%d\n", path, name, extension, size);
            }

            char fileNumber[FILE_NAME_LENGTH];
            char newfile[STRING_BUFFER] = "";
            sprintf(fileNumber, "%d", fileCount);
            buildDirectory(newfile, fileNumber, extension, outputDir);

            FILE *filePointer = fopen(newfile, "wb");
            writeData(filePointer, image, cluster, size, image[i] == DELETED);
            fileCount++;
        } else {
            int length = (int) strlen(path);
            strcat(path, name);
            if (startSector != (START_CLUSTER + cluster) && (cluster > 1)) {
                readWriteDirectory(image, START_CLUSTER + cluster, path, outputDir);
                path[length] = '\0';
            }
        }

        free(fileName);
        free(name);
        free(trimName);
        free(extension);
    }
}

/* Accepts parameters that include details about the file to be written. I dislike
 * recursion but it works! */
void writeData(FILE *destination, char *source, uint16_t cluster, uint32_t size, bool deleted) {
    if (cluster > 1 && size > 0) {
        int info = (START_CLUSTER + cluster) * SECTOR_SIZES;
        for (int i = info; i < info + SECTOR_SIZES && size > 0; i++, size--) {
            fprintf(destination, "%c", source[i]);
        }

        uint16_t nextCluster = nextFat(source, cluster);
        if (deleted) {
            if (nextCluster == 0) {
                nextCluster = cluster + 1;
            } else {
                return;
            }
        }

        /* Boundary condition for recursion. If next cluster is less than last good cluster and its not deleted,
         * next cluster is greater than one and next is not the same as cluster, or its deleted then write data */
        if (nextCluster <= LAST_GOOD_CLUSTER && ((nextCluster > 1 && !deleted && nextCluster != cluster) || deleted)) {
            writeData(destination, source, nextCluster, size, deleted);
        }
    }
}

/* Decodes FAT at specific cluster */
uint16_t nextFat(const char *image, uint16_t cluster) {
    int offset = FAT * SECTOR_SIZES;
    const int AMOUNT = 4;
    /* Equation for handling/ rearranging nibbles */
    offset += (cluster / 2) * (SIZE_FAT / SIZE_BYTE);
    if (cluster % 2 == 0) {
        /* First of two entries (1/2)  (Word) + Operator) */
        return ((*(uint16_t *) (image + offset)) & 0x0fff);
    } else {
        /* Second of two entries (2/2) (Word + Operator) */
        return *((uint16_t *) (image + offset + 1)) >> AMOUNT;
    }
}

/* removes trailing spaces from a string + replaces a deleted character with _ */
void reduceFileName(char *destination, const char *source) {
    for (int i = (int) strlen(source) - 1; i >= 0; i--) {
        if (strncmp(source + i, " ", 1) != 0) {
            /* Copy first num characters from source to destination */
            strncpy(destination, source, i + 1);
            destination[i + 1] = '\0';
            break;
        }
    }
    if (source[0] == DELETED) {
        destination[0] = '_';
    }
}

void buildDirectory(char *newFile, char *fileNum, char *extension, char *out) {
    /* Build directory */
    strcat(newFile, out);
    strcat(newFile, "/file");
    strcat(newFile, fileNum);
    strcat(newFile, ".");
    strcat(newFile, extension);
}
