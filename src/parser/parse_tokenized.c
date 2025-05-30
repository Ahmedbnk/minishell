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

void	process_command(t_data *tokenized, char **env)
{
  char	*in_file_name;
  char	*file_name;
  char	**command_and_args;
  int		fd_out;
  int		fd_in;

  in_file_name = NULL;
  file_name = NULL;
  command_and_args = get_cmd_and_its_args(tokenized);
  while (tokenized && tokenized->word != NULL && tokenized->type != PIPE)
  {
    if (tokenized->type == HEREDOC)
      in_file_name = tokenized->heredoc_file_name;
    else if (tokenized->type == REDIR_IN)
      handle_redir_in((tokenized + 1)->word, &in_file_name);
    else if (tokenized->type == REDIR_OUT)
      handle_redir_out((tokenized + 1)->word, &file_name);
    else if (tokenized->type == REDIR_APPEND)
      handle_append((tokenized + 1)->word, &file_name);
    tokenized ++;
  }
  if (file_name)
  {
    fd_out = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
  }
  if(in_file_name)
  {
    fd_in = open(in_file_name, O_CREAT | O_RDONLY, 0644);
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
  }
  execute_command(command_and_args[0], command_and_args, env);
  unlink(in_file_name);
}

void parse_tokenized(t_data *tokenized, char **env)
{
    int p[2];
    int prev;
    t_data *start;

    prev = -1;
    while (tokenized && tokenized->word)
    {
        start = tokenized;
        skip_command(&tokenized);
        if (tokenized && tokenized->type == PIPE)
            pipe(p);
        if (fork() == 0)
        {
            if (prev != -1)
            {
                dup2(prev, 0);
                close(prev);
            }
            if (tokenized && tokenized->type == PIPE)
            {
                close(p[0]);
                dup2(p[1], 1);
                close(p[1]);
            }
            process_command(start, env);
            exit(0);
        }
        if (prev != -1)
            close(prev);
        if (tokenized && tokenized->type == PIPE)
        {
            close(p[1]);
            prev = p[0];
            tokenized++;
        }
    }
    if (prev != -1)
        close(prev);
    while (wait(NULL) > 0);
}
