#include "minishell.h"

 int main()
{
  int i = 0;
  char *line;
  char **splitted;

   while(1)
   {
    handle_signals();
    line = readline(">>>> ");
    if(line && *line)
      add_history(line);
    if(line == NULL)
      return (0);
    if(check_error(line))
      return(1);
    splitted = customized_split(line);
    char *tmp;
    printf("splited of 0 is %s\n", *splitted);
    while(splitted[i])
    {
      tmp = splitted[i];
      splitted[i] = expand_if_possible(splitted[i]);
      free(tmp);
      i++;
    }
    i = 0;
    while(splitted[i])
    {
      remove_quotes(&splitted[i]);
      i++;
    }
    i = 0;
    while(splitted[i])
    {
      printf("%s\n", splitted[i]);
      i++;
    }

   }
   return (0);
}
