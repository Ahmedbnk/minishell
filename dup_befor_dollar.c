#include "minishell.h"

char *dup_befor_dollar(char *str, int *index)
{
  char *string;
  while(str[*index] && (str[*index] != '$' || !should_i_expand(str, *index)))
    (*index) ++;
  string = ft_strldup(str, *index);
  return string;
}
