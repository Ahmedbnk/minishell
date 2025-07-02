#include "minishell.h"

char **handle_dollar_with_quotes(char **splitted)
{
  int i = 0;
  while(splitted[i])
  {
    if(are_they_equal(splitted[i], "<<"))
      i++;
    else
      splitted[i] = remove_dollar_if_quotes_after_it(splitted[i]);
    i++;
  }
  return splitted;
}
