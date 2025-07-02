#include "minishell.h"

void	handle_signals(void)
{
  signal(SIGINT, handler);
  signal(SIGQUIT, SIG_IGN);
}
