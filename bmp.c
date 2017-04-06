#include "bmp_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

int get_file_size(FILE *fp)
{
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    rewind(fp);
    return sz;
}

void *r_shift_byte(void *pointer) { return (void *)(((byte *)pointer) + 1); }

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: bmp <code file>\n");
        return 0;
    }
    pixel *pixel_array;
    FILE *fp = fopen(argv[1], "rb");

    int sz = get_file_size(fp) + 1;
    int np = ceil(sz / 3.0);
    int width = sqrt(np);
    while (width % 4) {
        width++; // remove padding
    }
    int height = ceil(1.0 * np / width);
    int size = width * height;

    pixel_array = (pixel *)malloc(size * sizeof(pixel));
    memset(pixel_array, '\n', size * sizeof(pixel));
    pixel *head = pixel_array;
    pixel_array = (pixel *)r_shift_byte(pixel_array);

    while (fread(pixel_array++, sizeof(byte), 3, fp));

    int len = sizeof(argv[1]) + 10;
    char *filename = (char *)malloc(len);
    memset(filename, 0, len);
    strcat(filename, argv[1]);
    strcat(filename, ".bmp");
    write_to_bmp(width, height, head, filename);
    return 0;
}
