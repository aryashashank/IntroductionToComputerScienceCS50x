/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>

    typedef uint8_t BYTE;


int main()
{

    
    char* infile = "card.raw";
    // char* outfile;
    
    FILE* inptr = fopen(infile, "r");
    FILE* outptr;
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
    
    char blocks[512];
    int val=0,endoffile=0, flag=0;
    char name[8];
    endoffile=fread(&blocks,sizeof(BYTE)*512 , 1, inptr);
    while(endoffile==1){
    if(flag==0){
        if((BYTE)blocks[0]==0xff && (BYTE)blocks[1]==0xd8 && (BYTE)blocks[2]==0xff && ( (BYTE)blocks[3]>=0xe0 && (BYTE)blocks[3]<=0xef)){
            flag=1;
        }
    }
    if(flag==1 && (BYTE)blocks[0]==0xff && (BYTE)blocks[1]==0xd8 && (BYTE)blocks[2]==0xff && ( (BYTE)blocks[3]>=0xe0 && (BYTE)blocks[3]<=0xef )){
        if(val<10){
        sprintf(name,"00%i.jpg",val);
        }
        else if(val<100){
            sprintf(name,"0%i.jpg",val);
        }
        else{
            sprintf(name,"%i.jpg",val);
        }
        val++;
        outptr = fopen(name, "w");
        if (outptr == NULL)
        {
        printf("Could not open %s.\n", name);
        return 2;
        }
        fwrite(&blocks, sizeof(BYTE)*512, 1, outptr);
        flag=2;
    }
    if(!((BYTE)blocks[0]==0xff && (BYTE)blocks[1]==0xd8 && (BYTE)blocks[2]==0xff && ( (BYTE)blocks[3]>=0xe0 && (BYTE)blocks[3]<=0xef )) && flag==2){
    fwrite(&blocks, sizeof(BYTE)*512, 1, outptr);
    }
    
    endoffile=fread(&blocks,sizeof(BYTE)*512 , 1, inptr);
    
    if(flag==2 && (BYTE)blocks[0]==0xff && (BYTE)blocks[1]==0xd8 && (BYTE)blocks[2]==0xff && ( (BYTE)blocks[3]>=0xe0 && (BYTE)blocks[3]<=0xef )){
        fclose(outptr);
        flag=1;
        
    }
    if(endoffile!=1){
        fclose(outptr);
    }
    }
    fclose(inptr);
    return 0;
}