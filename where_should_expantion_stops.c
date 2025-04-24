#include "minishell.h"

char *where_should_expantion_stops(char *str)
{
  int i;

  i = 0;
  while(str[i])
  {
    if(str[i] == single_q || str[i] == double_q
      || str[i] == '$' || str[i] == '\0')
      return (i);
    i++;
  }
  return (i);
}
