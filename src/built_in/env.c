#include "minishell.h"

void env(char **env)
{
    if(!env || !*env)
        return;
    while(*env)
        printf("%s\n", *env++);
}


