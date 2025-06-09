#include "minishell.h"

void get_start_and_end(char *str, int *start, int *end)
{
  int i;
  i = 0;
  while(str[i])
  {
    if(str[i] == '=')
      *start = i+1;
    i++;
  }
  *end = i;
}

char *get_env_var(t_shell_control_block *shell , t_expand data)
{
  char **ptr = shell->env_cpy;
  char *value;
  int start;
  int end;

  int i ;
  i = 0;
  while(ptr[i])
  {
    
    if(compare_env_var(ptr[i], (data.to_expand)+1))
    {
      get_start_and_end(ptr[i], &start, &end);
      value = ft_substr(ptr[i], start, (end-start));
      return value;
    }
    i++;
  }
  return NULL;
}
