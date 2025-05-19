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
      create_heredoc((tokenized + 1) -> word);
    tokenized ++;
  }
}

void parse_tokenized(t_data *tokenized)
{
  while(tokenized && tokenized -> word != NULL)
  {
    // print_command(tokenized);
    process_command(tokenized);
    skip_command(&tokenized);
    if(tokenized -> word == NULL)
      return;
    else if(tokenized -> type == PIPE)
        tokenized ++;
  }
}
