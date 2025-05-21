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

void process_command(t_data *tokenized)
{
    if(!tokenized || tokenized->word == NULL || tokenized->type == PIPE)
    {
      printf("you are trying to process | or NULL word or tokenized is a NULL pointer \n");
      exit(1);
    }
    while(tokenized && tokenized->word != NULL && tokenized->type != PIPE)
    {
      if(tokenized -> type == HEREDOC)
        handle_heredoc((tokenized + 1) -> word);
      else if(tokenized ->type == REDIR_IN)
        handle_redir_in((tokenized + 1) -> word);
      else if(tokenized ->type == REDIR_OUT)
        handle_redir_out((tokenized + 1) -> word);
      else if(tokenized ->type == REDIR_APPEND)
        handle_append((tokenized + 1) -> word);
      close (0);
      open("tmp", O_CREAT| O_RDWR , 0777);
      tokenized ++;
    }
    unlink("tmp");
}

void parse_tokenized(t_data *tokenized)
{
  while(tokenized && tokenized -> word != NULL)
  {
    int rc = fork();
    if(rc == 0)
    {
      process_command(tokenized);
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
