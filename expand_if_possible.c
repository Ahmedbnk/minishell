#include "minishell.h"

void expand(char **string, char **expanded_string, int index)
{  
  char *str;
  int expantion_end;
  expantion_end = 0;
  str = ft_substr(*string, 0, index);
}
void expand_if_possible(char **string)
{
  int i = 0;
  char *str = *string;
  char *expanded_string;
  while(str[i])
  {
    if(str[i] == '$' && should_i_expand(str, i))
    {
      expand(string, &expanded_string, i);
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
