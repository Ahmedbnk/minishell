#include "minishell.h"

void check_built_in_command(char **cmd_and_args, char **env)
{
    (void ) env;
    if(are_they_equal(*cmd_and_args, "pwd"))
        exit((printf("%s\n",pwd()), 0));
    else if(are_they_equal(*cmd_and_args, "env"))
        exit((print_env(env), 0));
    else if(are_they_equal(*cmd_and_args, "echo"))
        exit((echo(cmd_and_args), 0));
    // else if(are_they_equal(*cmd_and_args, "cd"))
    //     exit((cd(*(cmd_and_args + 1), env), 0));
}