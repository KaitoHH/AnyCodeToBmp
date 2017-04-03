/**
 * Name: bmp file util
 * Author: KaitoHH
 * Description: This header implements a simple bmp-create function to 
 * construct a simple bmp image by passing a pixel array, where pixel
 * is a char[3] array. 
 * @see #write_to_bmp for more information
 *
 * All Rights Reserved 2017
**/
 
#pragma once
#include <stdio.h>

#define FW_OPEN(fp,name)  fp=fopen(filename, "wb");FILE *__fp=fp
#define FSW(d) fwrite(d,sizeof(unsigned char),1,__fp)
#define FDW(d) fwrite(d,sizeof(unsigned char),2,__fp)
#define FIW(d) fwrite(d,sizeof(unsigned int),1,__fp)
#define FPW(d) fwrite(d,sizeof(pixel),1,__fp)
#define FNPW(d,n) fwrite(d,sizeof(pixel),n,__fp)

typedef unsigned char pixel[3];
const unsigned char BMP_HEADER_BM[] = {0x42, 0x4d};
const unsigned int HEADER_SIZE = 0x36;
const unsigned int APPLICATION_PADDING = 0x0;
const unsigned int DIB_HEADER_SIZE = 0x28;
const unsigned short COLOR_PLANE = 1;
const unsigned short COLOR_BITS = 24;
const unsigned int BI_RGB = 0;
const unsigned int PRINT_WIDTH = 0;
const unsigned int PRINT_HEIGHT = 0;
const unsigned int PALETTE = 0;
const unsigned int NONE_COLOR = 0;
const unsigned char PADDING = 0;

unsigned int raw_bmp_size(unsigned int width, unsigned int height)
{
    return width * height * 3			// pixel
           + height * 2;				// padding
}

/**
 * Input: 
 * width: the width of the image
 * height: the height of the image
 * RGBArray: a one-dimension pixel array that stores color of pixels
 * filename: output filename
 * Output:
 * a file named filename, which is a bmp image file
**/
void write_to_bmp(unsigned int width, unsigned int height, pixel *RGBArray, char *filename)
{
    unsigned int raw_size = raw_bmp_size(width, height);
    unsigned int size = HEADER_SIZE	// bmp header size
                        + raw_size;

    FILE *fp;
    FW_OPEN(fp, filename);

    // BMP header
    FDW(BMP_HEADER_BM);
    FIW(&size);
    FIW(&APPLICATION_PADDING);
    FIW(&HEADER_SIZE);

    // DIB header
    FIW(&DIB_HEADER_SIZE);
    FIW(&width);
    FIW(&height);
    FDW(&COLOR_PLANE);
    FDW(&COLOR_BITS);
    FIW(&BI_RGB);
    FIW(&raw_size);
    FIW(&PRINT_WIDTH);
    FIW(&PRINT_HEIGHT);
    FIW(&PALETTE);
    FIW(&NONE_COLOR);

    int pad = (4 - width * 3 % 4) % 4;
    for(unsigned int i = 0; i < height; i++) {
        FNPW(RGBArray, width);
        for(int j = 0; j < pad; j++) {
            FSW(&PADDING);
        }
        RGBArray += width;
    }
    fclose(fp);
}

