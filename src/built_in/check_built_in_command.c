#include "minishell.h"

void check_built_in_command(char **cmd_and_args, char **env)
{
    (void ) env;
    if(are_they_equal(*cmd_and_args, "pwd"))
        exit((pwd(), 0));
    else 
        printf("nob");
}