#include "minishell.h"

void expand(char **string, int index)
{  
}
void expand_if_possible(char **string)
{
  int i = 0;
  char *str = *string;
  while(str[i])
  {
    if(str[i] == '$' && should_i_expand(str, i))
    {
      expand(string, i);
      return;
    }
    i++;
  }
}

  #include <stdio.h>
  int	main(void)
  {
    char *line = readline(">>> :");
    expand_if_possible(&line);
    return (0);
  }
