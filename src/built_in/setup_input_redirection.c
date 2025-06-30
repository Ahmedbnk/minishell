#include "minishell.h"

void setup_input_redirection(t_shell_control_block *shell)
{
  if (shell->in_file_name)
  {
    shell->fd_in = open(shell->in_file_name, O_RDONLY);
    dup2(shell->fd_in, 0);
    close(shell->fd_in);
  }
}
