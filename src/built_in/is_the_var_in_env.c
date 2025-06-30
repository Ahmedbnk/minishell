#include "minishell.h"

int is_the_var_in_env(char **env, char *var)
{
  while(*env)
  {
    if(compare_env_var(*env, var))
      return 1;
    env++;
  }
  return 0;
}
