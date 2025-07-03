#include "minishell.h"

void	setup_input_redirection(t_shell_control_block *shell)
{
	int	fd;

	if (shell->in_file_name)
	{
		shell->original_stdin = dup(0);
		fd = open(shell->in_file_name, O_RDONLY);
		dup2(fd, 0);
	}
}
