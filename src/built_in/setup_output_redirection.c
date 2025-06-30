#include "minishell.h"

void setup_output_redirection(t_shell_control_block *shell)
{
  if (shell->file_name)
  {
    shell->fd_out = open(shell->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    dup2(shell->fd_out, 1);
    close(shell->fd_out);
  }
}
