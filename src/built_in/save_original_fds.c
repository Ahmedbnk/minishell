#include "minishell.h"

void save_original_fds(t_shell_control_block *shell)
{
  shell->original_stdin = dup(0);
  shell->original_stdout = dup(1);
}
