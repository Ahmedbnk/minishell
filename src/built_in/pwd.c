#include "minishell.h"

#define  SIZE 4096

char *pwd(int *status)
{
    char *buffer;

    buffer = ft_malloc(SIZE, 1);
    if ((getcwd(buffer, SIZE) == NULL))
    {
       printf(" %s\n", strerror(errno));
       *status = 1;
       return NULL;
    }
    *status = 0;
    return buffer;
}
