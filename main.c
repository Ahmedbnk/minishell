#include "minishell.h"

void unused_vars(int ac, char **av , char **env);
char *ft_readline(void);
void expand_input(char **input);
void parse_and_expand(char *line, char *** splitted);

int main(int ac , char **av, char **env)
{

  char *line;
  char **splitted;
  splitted = NULL;
  t_list **to_free = get_garbage_pointer();

  unused_vars(ac, av, env);
  while(1)
  {
    handle_signals();
    line = ft_readline();
    if(line == NULL)
      return((free_memory_and_exit(*to_free),1));
    if(check_error(line))
      return((free_memory_and_exit(*to_free),1));
    parse_and_expand(line , &splitted);
  }
  free_memory_and_exit(*to_free);
  return (0);
}



void unused_vars(int ac, char **av , char **env)
{
  (void ) ac;
  (void) av;
  (void) env;
}

char *ft_readline(void)
{

  char *line;
  line = readline(">>>> ");
  if(line && *line)
    add_history(line);
  return line;
}

void expand_input(char **input)
{
  int i;
  i = 0;
  while(input[i])
  {
    input[i] = expand_if_possible(input[i]);
    i++;
  }
}

void parse_and_expand(char *line, char ***splitted)
{
  *splitted = customized_split(line);
  *splitted = split_with_operators(*splitted);
  expand_input(*splitted);

  t_data *tokenized = make_token(*splitted);
  if(tokenized)
  {
    remove_quotes_from_args(*splitted);
    parse_tokenized(tokenized);
  }
}
