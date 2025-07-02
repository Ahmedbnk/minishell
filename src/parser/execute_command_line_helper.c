#include "minishell.h"

void	execute_command_line_helper(t_shell_control_block *shell)
{
	int	p_id;

	get_cmd_and_its_args(shell);
	p_id = fork();
	if (p_id == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (shell->previous_read_end != -1)
			dup2(shell->previous_read_end, 0);
		if (shell->tokenze && shell->tokenze->word && shell->tokenze->type == PIPE)
		{
			pipe(shell->pipe_fd);
			dup2(shell->pipe_fd[1], 1);
			close(shell->pipe_fd[1]);
		}
		process_command(shell);
	}
	else
	{
		shell->last_child_pid = p_id;
		if (shell->previous_read_end != -1)
			close(shell->previous_read_end);
		if (shell->tokenze && shell->tokenze->word && shell->tokenze->type == PIPE)
		{
			close(shell->pipe_fd[1]);
			shell->previous_read_end = shell->pipe_fd[0];
			skip_command(&shell->tokenze);
			if (shell->tokenze && shell->tokenze->type == PIPE)
				shell->tokenze = shell->tokenze->next;
			shell->file_name_lst = NULL;
		}
	}
}
