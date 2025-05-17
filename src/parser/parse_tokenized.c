#include "minishell.h"

t_data *get_cmd_end(t_data *start)
{
  while(start)
  {
    if(start && start->type == PIPE)
      return (start);
    start ++;
  }
  return start;
}

char *get_infile_value(t_data *cmd_start, t_data *cmd_end)
{
  char *str;
  while(cmd_start != cmd_end)
  {
    if(cmd_start->type ==REDIR_IN)
      str = (cmd_start + 1) -> word;
    cmd_start ++;
  }
  return NULL;
}

char *get_outfile_value(t_data *cmd_start, t_data *cmd_end)
{
  char *str = NULL;
  while(cmd_start != cmd_end)
  {
    if(cmd_start->type ==REDIR_OUT || cmd_start->type == REDIR_APPEND)
      str = (cmd_start + 1) -> word;
    cmd_start ++;
  }
  return str;
}

 char **get_command_and_argumets_helper(t_data *pointer)
{
  char **command_and_arguments = ft_malloc(10000);
  int i = 0;
  while(pointer && pointer -> type != PIPE)
  {
    command_and_arguments[i] = pointer ->word;
    pointer ++;
    i++;
  }
  return command_and_arguments;
}

char **get_command_and_argumets(t_data *cmd_start, t_data *cmd_end)
{
  t_data *command_word_pointer;
  if(cmd_start->type == REDIR_IN)
    while(--cmd_end)
    {
      if(cmd_end->type == REDIR_IN)
        command_word_pointer = (cmd_end + 1);
    }
  else
    command_word_pointer = cmd_start;
  char **command_and_arguments = get_command_and_argumets_helper(command_word_pointer);
  print_splitted(command_and_arguments);
  return command_and_arguments;
}

void collect_cmd_info(t_data *cmd_start, t_data *cmd_end)
{
  char **command_and_arguments;
  char *in_file = NULL;
  char *out_file = NULL;

  in_file = get_infile_value(cmd_start, cmd_end);
  out_file = get_outfile_value(cmd_start, cmd_end);
  command_and_arguments = get_command_and_argumets(cmd_start, cmd_end);
}

void parse_tokenized(t_data *tokenized)
{
  t_data *cmd_start = tokenized;
  t_data *cmd_end = get_cmd_end(cmd_start);
  while(cmd_start)
  {
    collect_cmd_info(cmd_start, cmd_end);
    cmd_start =cmd_end;
    cmd_end = get_cmd_end(cmd_start);
  }
}
