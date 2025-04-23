#include "minishell.h"

int is_between_double_quotes(char *line, int index)
{
  int i;
  int quote;

  i = 0;
  quote = 0;
  while(line[i])
  {
    if(line[i] == double_q && quote == 0)
      quote = 1;
    else if(line[i] == double_q && 
        quote == 1)
      quote = 0;
    if(i == index)
      return(quote);
    i ++;
  }
  return(0);
}
