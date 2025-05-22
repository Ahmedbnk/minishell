#include "minishell.h"

void handle_redir_in(char *str, char *tmp_file_name)
{
  int fd;
  char *buffer;

  buffer = NULL;

  buffer = read_file(str);
  if(!buffer)
    return;
  fd = open(tmp_file_name, O_CREAT| O_RDWR | O_TRUNC, 0766);
  write(fd,buffer, ft_strlen(buffer));
  close(fd);
}
