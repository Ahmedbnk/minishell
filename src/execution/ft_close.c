#include "minishell.h"

void ft_close(int fd)
{
  if(fd < 0)
    return;
  close(fd);
}
