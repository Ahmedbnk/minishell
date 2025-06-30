#include "minishell.h"

static char **add_var_to_env(char **env , char *var)
{
    char **new_env;
    new_env = ft_malloc((len_of_two_d_array(env)+ 2) * sizeof(char *), 0);
    int i;
    i = 0;
    while(*env)
    {
        new_env[i] = ft_strdup(*env, 0);
        i++;
        env++;
    }
    new_env[i++] = ft_strdup(var, 0);
    new_env[i] = NULL;
    return new_env;
}
