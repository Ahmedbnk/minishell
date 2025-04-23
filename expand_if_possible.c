#include "minishell.h"
void expand_if_possible(char **string)
{
  int i = 0;
  char *str = *string;
  while(str[i])
  {
    if(str[i] == '$' && should_i_expand(str, i))
    {
      printf("expand %s at the index %d \n" ,str, i);
      return;
    }
    else
  {
      printf("we will not expand it\n");
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
