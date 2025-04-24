#include "minishell.h"

int find_separator_index(char *str)
{
  int i;
  i = 0;
  while(str[i])
  {
    if(is_separator_index(str[i]))
      return 1;
    i++;
  }
  return(0);
}
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
      expand(string, &expanded_string, &i);
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
