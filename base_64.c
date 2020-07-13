#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <b64/cdecode.h>
#include <b64/cencode.h>

int *base64_encode(const char *array, int bytes)
{
    char *output = (char*)malloc(bytes);
    char *c = output;
    int cnt = 0;

    base64_encodestate s;

    //start encodeing
    base64_init_encodestate(&s);
    cnt = base64_encode_block(array, strlen(array), c, &s);

    c += cnt;

    cnt = base64_encode_blockend(c, &s);
    c += cnt;
    *c = 0;
    
    printf("Base64 encoded:\n%s\n", output);

    return 0;

}

int *base64_decode(const char *array, int bytes)
{
    char *output = (char*)malloc(bytes);
    char *c = output;
    int cnt = 0;

    base64_decodestate s;

    //start decodeing
    base64_init_decodestate(&s);

    cnt = base64_decode_block(array, strlen(array), c, &s);
    c += cnt;

    *c = 0;

    printf("Base64 decoded:\n%s\n", output);

    return 0;
}

