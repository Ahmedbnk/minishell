#include "minishell.h"

void handle_append(char *str)
{
  close(1);
  int fd;

  fd = open(str, O_CREAT| O_RDWR | O_APPEND, 0777);
}
