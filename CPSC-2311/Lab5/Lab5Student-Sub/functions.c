#include "functions.h"
#include <string.h>

header_t read_header(FILE *image_file) {
    header_t header;
    fscanf(image_file, "%s %d %d %d ",
           //no ampersand
           header.MAGIC_NUMBER, &header.WIDTH, &header.HEIGHT, &header.MAX_COLOR);
    return header;
}

void write_header(FILE *out_file, header_t header) {
    fprintf(out_file, "%s %d %d %d ",
            header.MAGIC_NUMBER, header.WIDTH, header.HEIGHT, header.MAX_COLOR);
}

image_t *read_ppm(FILE *image_file) {
    header_t header = read_header(image_file);
    image_t * image = NULL;
    read_p6(image_file, header);
    //set image to read p6

    return image;
}

image_t *read_p6(FILE *image_file, header_t header) {
    //unsigned
    unsigned int num_pixels = header.HEIGHT * header.WIDTH;
    image_t *image = (image_t *) malloc(sizeof(image_t *));
    image->header = header;
    image->pixels = (pixel_t *) malloc(sizeof(pixel_t) * num_pixels);
    for (int i = 0; i < num_pixels; i++) {
        unsigned char r, g, b;
        fscanf(image_file, "%c%c%c", &r, &g, &b);
        image->pixels[i].R = r;
        image->pixels[i].G = g;
        image->pixels[i].B = b;
    }
    return image;
}


void write_p6(FILE *out_file, image_t *image) {
    //image is null
    header_t header = image->header;
    header.MAGIC_NUMBER[1] = '6';
    write_header(out_file, header);
    //unsigned
    unsigned int num_pixels = image->header.HEIGHT * image->header.WIDTH;
    for (int i = 0; i < num_pixels; i++) {
        fprintf(out_file, "%c%c%c",
                image->pixels[i].R,
                image->pixels[i].G,
                image->pixels[i].B
        );
    }
}

//never used
image_t *copy_image(image_t *image) {
    // Size of a header_t and a pointer to pixel data somewhere else in memory
    image_t *copy = (image_t *) malloc(sizeof(image_t));
    // Copy assignment of header info
    copy->header = image->header;
    //unsigned
    unsigned int num_pixels = copy->header.WIDTH * copy->header.HEIGHT;
    // Allocate memory for pixel data
    copy->pixels = (pixel_t *) malloc(sizeof(pixel_t) * num_pixels);
    // One line deep copy
    memcpy(copy->pixels, image->pixels, sizeof(pixel_t) * num_pixels);
    return copy;
}
