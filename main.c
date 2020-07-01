#include <stdio.h>
#include <unistd.h>

#include "identify.h"
#include "usage.h"

int main(int argc, char **argv)
{
    int opt;

    if((argc<2)||(argc>3))
    {
        usage();
        return 1;
        //exit(255);
    }
    if((identify(argv[1])!=0))
        while((opt = getopt(argc, argv, "vh")) != -1)
            switch(opt)
            {
                case 'v':
                    identify(argv[2]);
                    break;

                case 'h':
                    usage();
                    break;    
            default:
                perror("Error");
                return 1;
            }

    return 0;
}
