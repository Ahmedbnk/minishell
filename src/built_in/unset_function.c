#include "minishell.h"

int unset(char ***env, char **vars)
{
  while(*vars)
  {
    if(is_the_var_in_env(*env, *vars))
      remove_var_from_env(env, *vars);
    vars++;
  }
  return 0;
}
