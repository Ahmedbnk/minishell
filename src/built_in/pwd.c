#include "minishell.h"

#define  SIZE 4096

void pwd()
{
    char buffer[SIZE];

    if ((getcwd(buffer, SIZE) == NULL))
    {
       printf("%s\n", strerror(errno));
       return;
    }
    printf("%s\n", buffer);
}
