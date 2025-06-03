#include "minishell.h"

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

void parse_line(t_shell_block *shell_block)
{

  shell_block->splitted = customized_split(shell_block->line);
  shell_block->splitted = split_with_operators(shell_block->splitted);
  expand_input(shell_block->splitted);

  shell_block->tokenized = make_token(shell_block->splitted);
  if (shell_block->tokenized) {
    remove_quotes_from_args(shell_block->splitted);
    create_all_heredocs(shell_block->tokenized);
    execute_command_line(shell_block->tokenized,shell_block->env_cpy);
  }
}

char *ft_readline(t_shell_block *shell_block) {


  shell_block->line = readline("\001\033[1;31m\002⚡ Undefined Behavior ⚡ » \001\033[0m\002");
  if (shell_block->line && *shell_block->line)

    add_history(shell_block->line);
  if (shell_block->line == NULL)
  {
    free(shell_block->line);
    free_memory(*get_garbage_pointer());
    exit(0);
    return NULL;
  }
  if (check_error(shell_block->line ))
    return NULL;
  return shell_block->line;
}

void ft_init_shell_block(t_shell_block *shell_block, int ac, char **av)
{
  (void) ac;
  (void) av;
  shell_block->env_cpy = NULL;
  shell_block->line = NULL;
  shell_block->splitted = NULL;
}

int main(int ac, char **av, char **env)
{ 
  t_shell_block shell_block;

  ft_init_shell_block(&shell_block, ac, av);
  shell_block.env_cpy = copy_env(env);

 while (1) {
    handle_signals();
    if(!ft_readline(&shell_block))
      continue;
    parse_line(&shell_block);
  }
  return (0);
}

