#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cipherid(FILE **fp);

int identify(char *argv)
{
    FILE *fp;

    if((fp = fopen(argv, "r"))==0){
        perror("File not found or premission denied");
        return 1;
    }
    else{
        cipherid(&fp);
        fclose(fp);
    }

    return 0;
}

int cipherid(FILE **fp)
{
    int bytes=0, i=0, count=0, x=0;
    char *array;
    char c;

    fseek(*fp, 0, SEEK_END);
    bytes = ftell(*fp);
    rewind(*fp);

    array = calloc(bytes+1, sizeof(char));

   while((c = getc(*fp)) !=EOF)
   {
       for(i=0;i<=bytes;i++)
           if(array[i]==c){
               count=1;
               //break;
           }

       if(count == 0){
           array[x] = c;
           x++;
       }

       count = 0;
       printf("%c", c);
   }

    printf("%s\n", array);
    printf("%d\n", bytes);

    free(array);
    return 0;

}

