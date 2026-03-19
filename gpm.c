#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <stdbool.h>

typedef struct profile
{
    char* alias;
    char* name;
    char* email;
} profile_t;

int main(int argc, const char* argv[])
{
    FILE* file = fopen("./profiles.ini", "r");
    char buffer[128];

    while (fgets(buffer, 128, file))
    {
        printf("%s\n", buffer);
    }

    return 0;
}