#include "minishell.h"


void	handler(int signo)
{
  (void)signo;
	if (g_handler_state == 0)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
  else if(g_handler_state == 1)
  {
		write(1, "\n", 1);
    exit(130);
  }
}

void	handle_signals(void)
{
  signal(SIGINT, handler);
  signal(SIGQUIT, SIG_IGN);
}
