#include "minishell.h"

void handle_heredoc(char *str, char *tmp_file_name)
{
  int fd;
  char *buffer;

  remove_quotes(&str);
  buffer = NULL;
  
  fd = open(tmp_file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
  while(1)
  {
    buffer = readline("> ");
    if(buffer == NULL)
    {
      printf("warning: here-document delimited by end-of-file (wanted `%s')\n", str);
      break;
    }
    else if(are_they_equal(str, buffer))
      break;
    else
      buffer = expand_if_possible(buffer, 1);

    if(buffer == NULL)
    {
      printf("bash: warning: here-document at line 1 delimited by end-of-file (wanted `%s') ",str);
      return;
    }
    write(fd,buffer,ft_strlen(buffer));
    write(fd,"\n", 1);
  }
  close(fd);
}
