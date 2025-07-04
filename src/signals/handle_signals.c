#include "minishell.h"

void	handle_signals(void)
{
  t_shell_control_block *shell;

  shell = get_shell_pointer(NULL);
  shell ->old_sigint_handler = signal(SIGINT, handler);
  shell ->old_sigquit_handler = signal(SIGQUIT, SIG_IGN);
}
