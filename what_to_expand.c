#include "minishell.h"

char *what_to_expand(char *str, int *index)
{
  int start;
  char *to_expand;

  (*index) ++;
  start = *index;
  while(str[*index] && (!is_expand_separator(str[*index]) 
    || ((str[*index] == '$') && !should_i_expand(str, *index))))
    (*index) ++;
  to_expand =ft_strldup(str + start, *index - start);
  return to_expand;
}
