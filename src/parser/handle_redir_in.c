#include "minishell.h"

void handle_redir_in(char *str)
{
  int fd;
  char *buffer;

  buffer = NULL;

  buffer = read_file(str);
  fd = open("tmp", O_CREAT| O_RDWR | O_TRUNC, 0777);
  write(fd,buffer, ft_strlen(buffer));
  close(fd);
}
