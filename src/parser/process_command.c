#include "minishell.h"

void	process_command(t_shell_control_block *shell)
{
	shell->in_file_name = NULL;
	shell->file_name = NULL;
	handle_all_redir(shell);
  if(shell ->exit_status)
  {
    exit(1);
  }
	if (shell->file_name)
	{
		shell->fd_out = open(shell->file_name, O_CREAT | O_WRONLY | O_TRUNC,
				0644);
		dup2(shell->fd_out, 1);
	}
	if (shell->in_file_name)
	{
		shell->fd_in = open(shell->in_file_name, O_RDONLY);
		dup2(shell->fd_in, 0);
	}
	if (is_builtin(*shell->cmd_and_args))
		execute_builtin_child(shell);
	else
		execute_command(shell);
	if (shell->in_file_name)
		unlink(shell->in_file_name);
}
