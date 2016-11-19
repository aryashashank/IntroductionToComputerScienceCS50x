#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    else if(atoi(argv[1])<1 || atoi(argv[1])>100){
        printf("n should be between 1 and 100");
        return 2;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf,bfo;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi,bio;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    
    
    
    bfo=bf;
    bio=bi;
    bio.biWidth*=n;
    bio.biHeight*=n;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingout =  (4 - (bio.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bio.biSizeImage = (bio.biWidth * sizeof(RGBTRIPLE) + paddingout) * abs(bio.biHeight);
    bfo.bfSize = bio.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr);

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
      RGBTRIPLE triple[bi.biWidth];
        for (int j = 0; j < bi.biWidth; j++)
        {
            fread(&triple[j], sizeof(RGBTRIPLE), 1, inptr);
            
        }
        for(int vitr=0;vitr<n;vitr++){
            for(int aitr=0;aitr<bi.biWidth;aitr++){
        for(int hitr=0;hitr<n;hitr++){
              fwrite(&triple[aitr], sizeof(RGBTRIPLE), 1, outptr);  
        }
    }
        

        // then add it back (to demonstrate how)
        for (int k = 0; k < paddingout; k++)
        {
            fputc(0x00, outptr);
        }

        }
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
