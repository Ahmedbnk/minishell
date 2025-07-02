#include "minishell.h"

void	handler(int signo)
{
  (void)signo;
	if (set_handler_state(-1) == 0)
	{
    t_shell_control_block *ptr;
    ptr = get_shell_pointer(NULL);
    ptr ->exit_status =130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
  else if(set_handler_state(-1) == 1)
  {
		write(1, "\n", 1);
    exit(130);
  }
}
