#include "minishell.h"

int main()
{
  int i;
  char *line;
  char **splitted;
  t_list **to_free = get_garbage_pointer();

  while(1)
  {
    i = 0;
    handle_signals();
    line = readline(">>>> ");
    if(line && *line)
      add_history(line);
    if(line == NULL)
      return((free_memory_and_exit(*to_free),1));
    if(check_error(line))
      return((free_memory_and_exit(*to_free),1));
    splitted = customized_split(line);
    splitted = split_with_operators(splitted);
    while(splitted[i])
    {
      splitted[i] = expand_if_possible(splitted[i]);
      i++;
    }
    remove_quotes_from_args(splitted);
    print_splitted(splitted);
  }
  free_memory_and_exit(*to_free);
  return (0);
}
