#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <stdbool.h>
#include "strmnp.h"

typedef struct profile
{
    char* alias;
    char* name;
    char* email;
} profile_t;

int main(int argc, const char* argv[])
{
    // FILE* file = fopen("./profiles.ini", "r");
    // char buffer[128];

    // while (fgets(buffer, 128, file))
    // {
    //     printf("%s\n", buffer);
    // }

    printf("test\n");

    char* a = "   hi,\nhey,\nhello!,\nyo!\nyo\nm\nm\nm\nm\nm,   ";
    char b[12306];
    strcpy(b, a);
    char** c = malloc(sizeof(b));
    split(b, "\n", c);

    printf("%llu\n", sizeof(c));

    for (size_t i = 0; i < sizeof(b) / sizeof(char); i++)
    {
        printf("%s-", c[i]);
    }
    
    free(c);

    return 0;
}