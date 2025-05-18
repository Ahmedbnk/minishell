#include "minishell.h"

void create_heredoc(int *fd, char *str)
{
  *fd = open("tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
  char *buffer;
  while(1)
  {
    buffer = readline("heredoc >>>");
    if(are_they_equal(str, buffer))
      break;
    write(*fd,buffer,ft_strlen(buffer));
    write(*fd,"\n", 1);
  }
  //unlink("tmp");
  close(*fd);
}
