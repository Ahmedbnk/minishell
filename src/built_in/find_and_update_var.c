#include "minishell.h"

int find_and_update_var(char **env, char *var)
{
    int i;

    i = 0;

    while (env[i])
    {
        if (compare_env_var(env[i], var))
        {
            env[i] = ft_strdup(var, 0);
            return 1;
        }
        i++;
    }
    return 0;
}
