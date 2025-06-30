#include "minishell.h"

static void sort_env(char **env)
{
	int i;
	int j;
	i = 0;
	char *tmp;
		while(env[i])
		{
            j = i+1;
            while(env[j])
            {
                if(ft_strcmp(env[i], env[j]) > 0)
                {
                    tmp = env[i];
                    env[i] = env[j];
                    env[j] = tmp;
                }
                j++;
            }
			i++;
		}
    remove_var_from_env(&env, "_");
        print_env(env);
}
