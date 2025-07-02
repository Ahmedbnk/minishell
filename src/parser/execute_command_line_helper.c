#include "minishell.h"

void	execute_command_line_helper(t_shell_control_block *shell)
{
	int p_id;

	get_cmd_and_its_args(shell);
	p_id = fork();
	if (p_id == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (shell->previous_read_end != -1)
		{
			dup2(shell->previous_read_end, 0);
			ft_close(shell->previous_read_end);
		}
		if (shell->line_pointer && shell->line_pointer->type == PIPE)
		{
			ft_close(shell->previous_read_end);
			ft_close(shell->arr[0]);
			dup2(shell->arr[1], 1);
			ft_close(shell->arr[1]);
		}
		process_command(shell);
    exit(0);
	}
	else
		shell->last_child_pid = p_id;
}
