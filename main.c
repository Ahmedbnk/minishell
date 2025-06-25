#include "minishell.h"

int is_it_valid_dollar(char *str)
{
  int i;

  if(!str)
    return 0;
  i = 0;
  while (str[i])
  {
    if(is_dollar(str[i]) && !is_between_quotes(str, i) && str[i + 1] && !ft_isalnum(str[i + 1]))
      return 0;
    i++;
  }
  return 1;
}

int is_there_invalid_expantion(t_shell_control_block *sh, char *str, char *old_str)
{
  if(!is_it_valid_dollar(old_str))
  {
    rm_quotes_from_one_str(sh, &str);
    add_token_to_lst(&sh->tokenze, new_token(str, WORD));
    return 1;
  }
  return 0;
}

void split_after_expantion(t_shell_control_block *sh, char *str, char *old_str)
{
  int i;
  char **ptr;
  i = 0;
  if(!*str || is_there_invalid_expantion(sh, str, old_str))
	  return;
  ptr = customized_split(str);
  while (ptr[i])
  {
    rm_quotes_from_one_str(sh, &ptr[i]);
    add_token_to_lst(&sh->tokenze, new_token(ptr[i], WORD));
    i++;
  }
}

void expand_and_split_helper(t_shell_control_block *sh, int index)
{
	char *ptr;

	ptr = expand_if_possible(sh, sh->splitted[index], 0);
	if (are_they_equal(sh->splitted[index], ptr)) {
		rm_quotes_from_one_str(sh, &ptr);
	add_token_to_lst(&sh->tokenze, new_token(ptr, get_token_type(ptr)));
	}
	else
		split_after_expantion(sh, ptr, sh->splitted[index]);
}

void expand_and_split(t_shell_control_block *sh)
{
  int i;
  i = 0;

  sh->tokenze = NULL;
  while (sh->splitted[i])
  {
    if(are_they_equal(sh->splitted[i], "<<"))
    {
        add_token_to_lst(&sh->tokenze, new_token(sh->splitted[i], get_token_type(sh->splitted[i])));
		i++;
        add_token_to_lst(&sh->tokenze, new_token(sh->splitted[i], get_token_type(sh->splitted[i])));
	}
    else
		expand_and_split_helper(sh, i);
	i++;
  }
}

int parse_line(t_shell_control_block *sh)
{
  sh->porotect_var = generate_random_name();
  sh->splitted = customized_split(sh->line);
  sh->splitted = split_with_operators(sh->splitted);
  if(check_syntax_error(sh->splitted))
	  return 1;
  get_files_name(sh);
  expand_and_split(sh);
  return 0;
}

void execute_line(t_shell_control_block *sh)
{
  if (sh->tokenze)
  {
    create_all_heredocs(sh);
    get_cmd_and_its_args(sh);
    if(!is_there_a_pipe(sh) && execute_built_in(sh, parent));
    else
      execute_command_line(sh);
  }
}

char *ft_readline(t_shell_control_block *sh)
{
  sh->line = readline("\001\033[1;31m\002 Undefined Behavior :\001\033[0m\002");
  if (sh->line && *sh->line)

    add_history(sh->line);
  if (sh->line == NULL)
  {
    free(sh->line);
    free_memory(get_garbage_pointer(1));
    free_memory(get_garbage_pointer(0));
    exit(0);
  }
  if (check_error(sh))
    return((free(sh->line), NULL));
  return sh->line;
}

void ft_init_shell_block(t_shell_control_block *sh, int ac, char **av)
{
  (void) ac;
  (void) av;
  sh->env_cpy = NULL;
  sh->line = NULL;
  sh->splitted = NULL;
  sh->file_name_lst = NULL;
  sh->tokenze = NULL;
  sh->cmd_and_args= NULL;
  sh->env_of_export = NULL;
  sh->exit_status= 0;
}

int main(int ac, char **av, char **env)
{
  t_shell_control_block sh;

  ft_init_shell_block(&sh, ac, av);
  sh.env_of_export = copy_env(env);
  sh.env_cpy = copy_env(env);
 while (1) {
   handle_signals(0);
   if (!ft_readline(&sh) || parse_line(&sh))
     continue;
    execute_line(&sh);
    free_memory(get_garbage_pointer(1));
    free(sh.line);
  }
  return (0);
}
