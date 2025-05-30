#include "minishell.h"

// void handle_heredoc(t_data *tokenized , char **in_file_name)
// {
//   *in_file_name = tokenized -> heredoc_file_name;
// }
//
void create_heredoc(t_data *tokenized)
{
  int fd;
  char *file_name = ft_strjoin("/tmp/", generate_random_name());
  char *str = NULL; 
  char *buffer = NULL; 

  tokenized->heredoc_file_name = (tokenized + 1) -> word;
  while(1)
  {
    str = readline(">>>");
    if(str == NULL)
    {
      print_error("warning: here-document delimited by end-of-file (wanted `%s')\n", str);
      break;
    }
    if(are_they_equal(str, tokenized->heredoc_file_name))
       break;
    buffer = ft_strjoin(buffer, str);
  }
  fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
  write(fd,buffer,ft_strlen(buffer));
  write(fd,"\n", 1);
  close(fd);
}

void create_all_heredocs(t_data *tokenized)
{
  while(tokenized && tokenized -> word)
  {
    if(tokenized -> type == HEREDOC)
      create_heredoc(tokenized);
    tokenized ++;
  }
}
