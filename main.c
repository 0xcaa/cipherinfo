#include <stdio.h>
#include <unistd.h>

#include "identify.h"

int main(int argc, char **argv)
{
    int opt;
    /*
    if (argc!=2)
    {
        printusage(argv[0]);
        exit(255);
    }
    */

    while((opt = getopt(argc, argv, "i")) != -1)
        switch(opt)
        {
            case 'i':
                identify(argv[2]);
                break;
     
        default:
            perror("Invalid Option");
            return 1;
        }

    return 0;
}
