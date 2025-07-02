#include "minishell.h"

void remove_var_from_env(char ***env , char *var)
{
  char **env_after_unset;
  int i;
  i = 0;

  env_after_unset = ft_malloc(len_of_two_d_array(*env) * sizeof(char *), 0);
  while(**env)
  {
    if(!compare_env_var(**env, var))
      env_after_unset[i++]=  ft_strdup(**env, 0);
    (*env)++;
  }
  env_after_unset[i] = NULL;
  *env = env_after_unset;
}
