
#include "minishell.h"

token_t get_token_type(const char *str) {
  if (are_they_equal(str, "|"))
    return TOKEN_PIPE;
  else if (are_they_equal(str, "<"))
    return TOKEN_REDIR_IN;
  else if (are_they_equal(str, ">"))
    return TOKEN_REDIR_OUT;
  else if (are_they_equal(str, ">>"))
    return TOKEN_REDIR_APPEND;
  else if (are_they_equal(str, "<<"))
    return TOKEN_HEREDOC;
    // else if (are_they_equal((const char *)str, ""))
    //     return TOKEN_EOF;
  else
    return TOKEN_WORD;
}

t_token    *get_data(t_token *data, char **spliteed)
{
  int i;
  i = 0;
  while(spliteed[i])
  { 
    data[i].type = get_token_type(spliteed[i]);
    data[i].word = spliteed[i];
    //printf("%s\n", data[i].word );
    i++;
  }
  return data;

}

int tcheck_redirections(t_token *data)
{
  int i ;
  i = 0;
  while(i < 3)
  {
    if(data[i].type == TOKEN_REDIR_OUT && data[i+1].type != TOKEN_WORD)
      return 1;
    else if(data[i].type == TOKEN_REDIR_IN && data[i+1].type != TOKEN_WORD)
      return 1;
    //else if(data[i].type == TOKEN_REDIR_APPEND && data[i+1].type != TOKEN_WORD)
    // return 1;
    else if(data[i].type == TOKEN_HEREDOC && data[i+1].type != TOKEN_WORD)
      return 1;
    i++;
  }
  return 0;
}

int tcheck_pipe_character(t_token *data)
{
  int i ;
  i = 0;
  while(i < 3)
  {
    if(data[i].type == TOKEN_PIPE && i  == 0)
      return 1;
    if(data[i].type == TOKEN_PIPE && (data[i-1].type != TOKEN_WORD || data[i+1].type != TOKEN_WORD) && i > 0)
      return 1;
    i++;
  }
  return 0;
}
int tcheck_data_error(t_token *data)
{
  if(tcheck_pipe_character(data) || tcheck_redirections(data))
  {
    return ((printf("syntax error near unexpected token `newline'\n"), 1));
  }
  return 0;
}

int main()
{
  t_token data[4];
  char *str[] = {"a", "|" , "", NULL};
  get_data(data, str);
  tcheck_data_error(data);
  //printf("%d\n", ptr[0].type);
  printf("%d\n", data[1].type);
  printf("%d\n", data[2].type);
  printf("\nend.\n");
}
