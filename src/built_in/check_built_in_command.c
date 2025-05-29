#include "minishell.h"

void check_built_in_command(char **cmd_and_args, char **env)
{
    (void ) env;
    if(are_they_equal(*cmd_and_args, "pwd"))
        exit((pwd(), 0));
    else if(are_they_equal(*cmd_and_args, "env"))
        exit((print_env(env), 0));
    else if(are_they_equal(*cmd_and_args, "echo"))
        exit((echo(cmd_and_args), 0));
    //else if(are_they_equal(*cmd_and_args, "cd"))
        //exit((cd, 0));
}