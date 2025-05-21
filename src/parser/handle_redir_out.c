#include "minishell.h"

void handle_redir_out(char *str)
{
  close(1);
  int fd;

  fd = open(str, O_CREAT| O_RDWR | O_TRUNC, 0777);
}
