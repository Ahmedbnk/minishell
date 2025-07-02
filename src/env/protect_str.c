#include "minishell.h"

char *protect_str(t_shell_control_block *sh ,char *str)
{
  char *new_str;
  int i;
  int j;
  int size;
  size = ft_strlen(str) + (ft_strlen(sh->porotect_var) * count_number_of_qute(str)) + 1;
  new_str = ft_malloc(size, 1);
  i = 0;
  while (*str)
  {
    j = 0;
    if(is_quote(*str))
    {
      new_str[i++] = *str;
      while(sh->porotect_var[j])
        new_str[i++] = sh->porotect_var[j++];
    }
    else
      new_str[i++] = *str;
    str++;
  }
  new_str[i] = '\0';
  return new_str;
}
