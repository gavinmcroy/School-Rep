//
// Created by Gavin Taylor Mcroy on 12/1/21.
//

#ifndef INC_3220_NOTJUSTCATS_H
#define INC_3220_NOTJUSTCATS_H

#define FAT 1
#define ROOT 19
#define START_CLUSTER 31 // 33 - 2
#define SECTOR_SIZES 0x200
#define SIZE_BYTE 4
#define SIZE_FAT 12
#define FILE_NAME_OFFSET 0
#define FILE_NAME_LENGTH 8
#define FILE_SIZE_OFFSET 28
#define EXT_OFFSET 8
#define EXT_LENGTH 3
#define ATTR_OFFSET 11
#define FIRST_CLUSTER_OFFSET 26
#define DIRECTORY_ENTRY_SIZE 32
#define DIRECTORY 0x10
#define LAST_GOOD_CLUSTER 0xFEF
#define DELETED (char)0xE5


#define STRING_BUFFER 256

uint16_t nextFat(const char *image, uint16_t cluster);

void reduceFileName(char *destination, const char *source);

void readWriteDirectory(char *image, int startSector, char *path, char *outputDir);

void writeData(FILE *destination, char *source, uint16_t cluster, uint32_t size, bool deleted);

void buildDirectory(char *newFile, char *fileNum, char *extension, char *out);

#endif //INC_3220_NOTJUSTCATS_H
