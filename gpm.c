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
    for (size_t i = 0; i < argc; i++)
    {
        printf("%llu: %s, ", i, argv[i]);
    }
    printf("\n");

    printf("%i\n", argc);
    const char* mode = argv[1];

    // gpm status
    // gpm switch <alias>

    if (argc != 1)
    {
        if (strcmp(mode, "status") == 0)
        {
            printf("\x1b[32mUsername:\x1b[39m\n");
            system("git config get user.name");
            printf("\x1b[32mEmail:\x1b[39m\n");
            system("git config get user.email");
        }
        else if (strcmp(mode, "list") == 0)
        {
            char total[] = "";

            FILE* file = fopen("./profiles.conf", "r");
            char buffer[128];

            while (fgets(buffer, 128, file))
            {
                strcat(total, buffer);
                char* name = "NONE";
                char* email = "NONE";

                char* token = strtok(buffer, " = ");
                char* prev_token = "";
                while (token != NULL)
                {
                    if (strchr(token, '\"') != NULL || strchr(token, '\'') != NULL)
                    {
                        if (strcmp(prev_token, "name"))
                        {
                            name = token;
                            printf("found: %s\n", name);
                        }
                        else if (strcmp(prev_token, "email"))
                        {
                            email = token;
                            printf("found: %s\n", email);
                        }
                    }

                    *prev_token = *token;
                    token = strtok(NULL, " = ");
                }
            
                printf("name: %s\nemail: %s\n", name, email);
            }

            fclose(file);
        }
        else
        {
            printf("aint a command mayte\n");
        }
    }

    return 0;
}