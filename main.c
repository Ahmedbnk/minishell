#include "minishell.h"

int main()
{
  int i = 0;
  char *line;
  char **splitted;
  t_list **to_free = get_garbage_pointer();

  while(1)
  {
    handle_signals();
    line = readline(">>>> ");
    if(line && *line)
      add_history(line);
    if(line == NULL)
      return((free_memory_and_exit(*to_free),1));
    if(check_error(line))
      return((free_memory_and_exit(*to_free),1));
    splitted = customized_split(line);
    while(splitted[i])
    {
      splitted[i] = expand_if_possible(splitted[i]);
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
  free_memory_and_exit(*to_free);
  return (0);
}
