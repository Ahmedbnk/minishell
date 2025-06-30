#include "minishell.h"

int compare_env_var(char *var1, char *var2)
{
  int i ;
  i = 0;
  while((var2[i] && var2[i] != '=') || var1[i] != '=' )
  {
    if(var1[i] != var2[i])
      return 0;
    i++;
  }
  return 1;
}
