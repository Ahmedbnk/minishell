#include "minishell.h"

int is_it_valid_dollar(char *str)
{
  int i;

  if(!str)
    return 0;
  i = 0;
  while (str[i])
  {
    if(is_dollar(str[i]) && !is_between_quotes(str, i) && str[i + 1] && !ft_isalnum(str[i + 1]))
      return 0;
    i++;
  }
  return 1;
}
