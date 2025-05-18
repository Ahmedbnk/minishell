#include "minishell.h"

void create_heredoc(int *fd)
{
  *fd = open("tmp", O_CREATE | O_RDWR);
}
