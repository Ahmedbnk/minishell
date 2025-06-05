#include "minishell.h"

int	generate_random_number(void)
{
  int	fd;
  int	random_number;

  fd = open("/dev/random", O_RDONLY);
  read(fd, &random_number, 4);
  close(fd);
  if (random_number < 0)
    return (-random_number);
  return (random_number);
}

char	*generate_random_name(void)
{
  int	num;

  num = generate_random_number();
  if (num < 0)
    return (NULL);
  return (ft_itoa(num));
}



void	skip_command(t_data **tokenized_address)
{
  t_data	*tokenized;

  tokenized = *tokenized_address;
  while (tokenized && tokenized->word != NULL && tokenized->type != PIPE)
    tokenized ++;
  *tokenized_address = tokenized;
}

void	print_command(t_data *tokenized)
{
  while (tokenized && tokenized->word != NULL && tokenized->type != PIPE)
  {
    printf("%s ", tokenized->word);
    tokenized ++;
  }
  printf("\n");
}

void	process_command(t_data *tokenized, t_shell_control_block *shell)
{
  char	*in_file_name;
  char	*file_name;
  int		fd_out;
  int		fd_in;
  in_file_name = NULL;
  file_name = NULL;
  get_cmd_and_its_args(shell);
  while (tokenized && tokenized->word != NULL && tokenized->type != PIPE)
  {
    if (tokenized->type == HEREDOC)
      in_file_name = tokenized->heredoc_file_name;
    else if (tokenized->type == REDIR_IN) handle_redir_in((tokenized + 1)->word, &in_file_name);
    else if (tokenized->type == REDIR_OUT)
      handle_redir_out((tokenized + 1)->word, &file_name);
    else if (tokenized->type == REDIR_APPEND)
      handle_append((tokenized + 1)->word, &file_name);
    tokenized ++;
  }
  if (file_name)
  {
    fd_out = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    dup2(fd_out, 1);
    close(fd_out);
  }
  if(in_file_name)
  {
    fd_in = open(in_file_name, O_CREAT | O_RDONLY, 0644);
    dup2(fd_in, 0);
    close(fd_in);
  }
  if(!execute_built_in(shell))
    execute_command(shell);
  unlink(in_file_name);
}

void execute_command_line(t_shell_control_block *shell)
{
  int arr[2];
  int previous_read_end;
  t_data *line_pointer;

  line_pointer = shell->tokenized;
  previous_read_end = -1;
  while (line_pointer && line_pointer->word)
  {
    shell->tokenized = line_pointer;
    skip_command(&line_pointer);
    if (line_pointer && line_pointer->type == PIPE)
      pipe(arr);
    if (fork() == 0)
    {
      if (previous_read_end != -1)
      {
        dup2(previous_read_end, 0);
        close(previous_read_end);
      }
      if (line_pointer && line_pointer->type == PIPE)
      {
        close(previous_read_end);
        close(arr[0]);
        dup2(arr[1], 1);
        close(arr[1]);
      }
      process_command(shell->tokenized, shell);
      exit(0);
    }
    if (previous_read_end != -1)
      close(previous_read_end);
    if (line_pointer && line_pointer->type == PIPE)
    {
      close(arr[1]);
      previous_read_end =arr[0];
      line_pointer++;
    }
  }
  if (previous_read_end != -1)
    close(previous_read_end);
  while (wait(NULL) > 0);
}
