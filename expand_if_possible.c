#include "minishell.h"

//char *find_separator_index(char *str)
//{
//  int i;
//  i = 0;
//  while(str[i])
//  {
//    if(is_separator_index(str[i]))
//      return &str[i];
//    i++;
//  }
//  return(0);
//}
char *get_env_value(const char *var_name)
{
    char *value = getenv(var_name);
    if (!value)
        return strdup("");
    return strdup(value);
}


void expand_if_possible(char **string)
{
  int i = 0;
  char *str = *string;
  while(str[i])
  {
    if(str[i] == '$' && should_i_expand(str, i))
    {
      char *string = expand(str);
      printf("the string is %s\n", string);
      return;
    }
    i++;
  }
}

  #include <stdio.h>
  int	main(void)
  {
  while(1)
  {
    char *line = readline(">>> :");
    expand_if_possible(&line);
  }
  return (0);
  }
