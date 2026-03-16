#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>

typedef struct profile
{
    char* name, email;
} profile_t;

int main(int argc, const char* argv[])
{
    // gpm status
    // gpm switch <alias>

    if (argc == 2)
    {
        if (strcmp(argv[1], "status") == 0)
        {
            printf("\x1b[32mUsername:\x1b[39m\n");
            system("git config get user.name");
            printf("\x1b[32mEmail:\x1b[39m\n");
            system("git config get user.email");
        }
    }
    
    if (argc >= 3)
    {
        if (strcmp(argv[1], "switch") == 0)
        {
            const char* profile = argv[2];
            char* profile_header = "[";
            profile_header = strcat(profile_header, profile);
            profile_header = strcat(profile_header, "]");

            printf("%s\n", profile);
            printf("%s\n", profile_header);

            FILE* file = fopen("./profiles.conf", "r");
            char buffer[128];

            while (fgets(buffer, 128, file))
            {
                printf("%s", buffer);

                // if (strcmp(profile_header, buffer) == 0)
                // {
                //     printf("%s found\n", profile);
                // }
            }

            fclose(file);
        }
    }

    return 0;
}