#include "minishell.h"

void unused_vars(int ac, char **av, char **env);
char *ft_readline(void);
void expand_input(char **input);
void parse_and_expand(char *line, char ***splitted, char **env);

int main(int ac, char **av, char **env) {

  char *line;
  char **splitted;
  splitted = NULL;
  //t_list **to_free = get_garbage_pointer();

  unused_vars(ac, av, env);
  while (1) {
    line = ft_readline();
    if(!line)
      return 0;
    int rc = fork();
    if(rc == 0)
    {
      if (check_error(line))
        free_memory_and_exit(*get_garbage_pointer());

      handle_signals_in_child();
      parse_and_expand(line, &splitted, env);
    }
    else
    wait(NULL);
    free(line);
  }
  return (0);
}

void unused_vars(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  (void)env;
}

char *ft_readline(void) {

	char *line;

	handle_signals();

	line = readline("\001\033[1;31m\002⚡ Undefined Behavior ⚡ » \001\033[0m\002");
	if (line && *line)
		add_history(line);
	if (line == NULL)
	{
    free(line);
    free_memory_and_exit(*get_garbage_pointer());
    return NULL;
	}
 return line;
}

void expand_input(char **input) {
  int i;
  i = 0;
  while (input[i]) {
		if(are_they_equal(input[i], "<<"))
			i++;
		else
			input[i] = expand_if_possible(input[i], 0);
    i++;
  }
}

void parse_and_expand(char *line, char ***splitted, char **env)
{
  *splitted = customized_split(line);
  *splitted = split_with_operators(*splitted);
  expand_input(*splitted);

  t_data *tokenized = make_token(*splitted);
  if (tokenized) {
    remove_quotes_from_args(*splitted);
    parse_tokenized(tokenized, env);
  }
}
