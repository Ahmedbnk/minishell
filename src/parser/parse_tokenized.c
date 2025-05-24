#include "minishell.h"

void skip_command(t_data **tokenized_address)
{
  t_data *tokenized;

  tokenized = *tokenized_address;
  while(tokenized && tokenized->word !=NULL && tokenized->type != PIPE)
    tokenized ++;

  *tokenized_address = tokenized;
}

void print_command(t_data *tokenized)
{
  if(!tokenized || tokenized->word == NULL || tokenized->type == PIPE)
  {
    printf("you are trying to print | or NULL word or tokenized is a NULL pointer \n");
    exit(1);
  }
  while(tokenized && tokenized->word != NULL && tokenized->type != PIPE)
  {
    printf("%s", tokenized -> word);
    tokenized ++;
  }
  printf("\n");
}

int generate_random_number()
{
    int fd = open("/dev/random", O_RDONLY);

    int random_number;
    read(fd, &random_number, 4);
    close(fd);
  if(random_number < 0)
    return (-random_number);
  return random_number;
}

char *generate_random_name()
{
    int num = generate_random_number();
    if (num < 0)
        return NULL; 

    return ft_itoa(num);
}


void process_command(t_data *tokenized, char **env)
{
  char *tmp_file_name;

    tmp_file_name = generate_random_name();
    tmp_file_name = ft_strjoin("/tmp/heredoc_", tmp_file_name);

    if(!tokenized || tokenized->word == NULL || tokenized->type == PIPE)
    {
      printf("you are trying to process | or NULL word or tokenized is a NULL pointer \n");
      exit(1);
    }
	char ** command_and_args = get_cmd_and_its_args(tokenized);
    while(tokenized && tokenized->word != NULL && tokenized->type != PIPE)
    {
      if(tokenized -> type == HEREDOC)
        handle_heredoc((tokenized + 1) -> word, tmp_file_name);
      else if(tokenized ->type == REDIR_IN)
        handle_redir_in((tokenized + 1) -> word, tmp_file_name);
      else if(tokenized ->type == REDIR_OUT)
        handle_redir_out((tokenized + 1) -> word);
      else if(tokenized ->type == REDIR_APPEND)
        handle_append((tokenized + 1) -> word);
      tokenized ++;
    }
   close(0);
   open(tmp_file_name, O_CREAT| O_RDWR , 0644);
	 execute_command(*command_and_args, command_and_args, env);
   unlink(tmp_file_name);
}

void parse_tokenized(t_data *tokenized, char **env)
{
  while(tokenized && tokenized -> word != NULL)
  {
    int rc = fork();
    if(rc == 0)
    {
      process_command(tokenized, env);
      exit(1);
    }
    else
    wait(NULL);
    skip_command(&tokenized);
    if(tokenized -> word == NULL)
      return;
    else if(tokenized -> type == PIPE)
      tokenized ++;
  }
}
