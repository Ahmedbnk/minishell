/*                                                        :::      ::::::::   */
/*   execute_command_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:01 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 17:19:07 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	iteration(t_shell *shell)
{
	while (shell->line_pointer && shell->line_pointer->word)
	{
		shell->tokenze = shell->line_pointer;
		skip_command(&(shell->line_pointer));
		if (shell->line_pointer && shell->line_pointer->type == PIPE)
			ft_pipe(shell->arr);
		execute_command_line_helper(shell);
		skip_ambig_list(shell);
		if (shell->previous_read_end != -1)
			close(shell->previous_read_end);
		if (shell->line_pointer && shell->line_pointer->type == PIPE)
		{
			close(shell->arr[1]);
			shell->previous_read_end = shell->arr[0];
			shell->line_pointer = shell->line_pointer->next;
		}
	}
}

void	execute_command_line(t_shell *shell)
{
	int	status;
	int	var_print_signal;

	var_print_signal = 0;
	status = 0;
	shell->line_pointer = shell->tokenze;
	shell->previous_read_end = -1;
	set_handler_state(2);
	iteration(shell);
	if (shell->previous_read_end != -1)
		close(shell->previous_read_end);
	waitpid(shell->last_child_pid, &status, 2);
	if (WIFEXITED(status) && !shell->exit_status_flag)
		exstat(WEXITSTATUS(status));
	else if (WIFSIGNALED(status) && !shell->exit_status_flag)
	{
		var_print_signal = 1;
		exstat(128 + WTERMSIG(status));
	}
	if (exstat(-1) > 128 && var_print_signal && !shell->exit_status_flag)
		print_exit_signal_message(exstat(-1));
	while (wait(NULL) > 0)
		;
}
