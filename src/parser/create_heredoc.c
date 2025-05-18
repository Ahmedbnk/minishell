#include "minishell.h"

void create_heredoc(int *fd, char *str)
{
  *fd = open("tmp", O_CREAT | O_RDWR);
  char *buffer;
  while(1)
  {
    buffer = readline("heredoc >>>");
    if(are_they_equal(str, buffer))
      break;
  }
  unlink("tmp");
  close(*fd);
}
