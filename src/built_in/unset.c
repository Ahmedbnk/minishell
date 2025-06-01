#include "minishell.h"


// void find_var(char **env, char *var)
// {
//     int i;
//     i = 0;
//     while(env[i])
//     {
//         if(ft_strncmp(env[i], "OLDPWD=", 7) == 0)
//             env[i] = ft_strdup(ft_strjoin("OLDPWD=", old_dir));
//         else if(ft_strncmp(env[i], "PWD=", 4) == 0)
//             env[i] = ft_strdup(ft_strjoin("PWD=", new_dir));
//         i++;
//     }
// }

void unset(char **env, char *var);
