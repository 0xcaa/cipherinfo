#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "base_64.h"

int array_lenght(char *array);
int cipherid(FILE **fp, int bytes);

int identify(char *argv)
{
    FILE *fp;
    char *file_array, c;
    int bytes, j=0;

    if((fp = fopen(argv, "r"))==0){
        if((strcmp(argv, "-v"))==0)
            return 1;
        fprintf(stderr, "Premission denied or invalid file\n");
        return 1;
    }
    else{
        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        rewind(fp);

        cipherid(&fp, bytes);

        file_array = calloc(bytes+1, sizeof(char));

        while((c = getc(fp))!=EOF){
            file_array[j] = c;
            //printf("%c", c);
            j++;
        }
        base64_decode(file_array, bytes);
        base64_encode(file_array, bytes);
        
        
        fclose(fp);
        free(file_array);
        return 0;
    }
}

int cipherid(FILE **fp, int bytes)
{
    int i, count=0, x=0;
    char *array;
    char c;

    array = calloc(bytes+1, sizeof(char));

    while((c = getc(*fp)) !=EOF)
    {
       for(i=0;i<=bytes;i++)
           if(array[i]==c){
               count=1;
               break;
           }

       if((count == 0)&&(c>32)){
           array[x] = c;
           x++;
       }

       count = 0;
       //printf("%c", c);
    }

    printf("Unique characters:\n%s\n", array);
    printf("%d\n\n", array_lenght(array));

    free(array);
    rewind(*fp);
    return 0;

}
int array_lenght(char *array)
{
    int q, lenght=0;

    for(q=0;array[q]!=0;q++)
        lenght++;

    return lenght;
}

