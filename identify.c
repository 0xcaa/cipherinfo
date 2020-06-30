#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cipherid(FILE **fp);

int identify(char *argv)
{
    FILE *fp;

    if((fp = fopen(argv, "r"))==0){
        if((strcmp(argv, "-v"))==0)
            return 1;
        fprintf(stderr, "Premission denied or invalid file\n");
        return 1;
    }
    else{
        cipherid(&fp);
        fclose(fp);
        return 0;
    }
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
               break;
           }

       if((count == 0)&&(c>32)){
           array[x] = c;
           x++;
       }

       count = 0;
       //printf("%c", c);
   }

    printf("%s\n", array);
    //print how many unik chars
    //printf("%d\n", bytes);

    free(array);
    return 0;

}

