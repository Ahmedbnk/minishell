#include "minishell.h"

char *dup_befor_dollar(char *str, int *index)
{
  int i;

  i = 0;
  char *string;
  while(str[i] && (str[i] != '$' || !should_i_expand(str, i)))
    i++;
  string = ft_strldup(str, i);
  index += i;
  return string;
}
