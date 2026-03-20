#include "strmnp.h"

char* strip(char string[])
{
    char* new_string;
    size_t start, end;

    for (size_t i = 0; i < strlen(string); i++)
    {
        if (string[i] != ' ' && string[i] != '\n')
        {
            start = i;
            break;
        }
    }
    
    for (size_t i = strlen(string) - 1; i > 0; i--)
    {
        if (string[i] != ' ' && string[i] != '\n')
        {
            end = i + 1;
            break;
        }
    }

    for (size_t i = start, c = 0; i < end && c < end - start; i++, c++)
    {
        new_string[c] = string[i];
    }
    
    return new_string;
}

void split(char string[], char* delimiter, char* dest[])
{
    char* line = strtok(string, delimiter);
    size_t i = 0;

    while (line != NULL)
    {
        dest[i] = line;
        i++;
        line = strtok(NULL, delimiter);
    }
}
