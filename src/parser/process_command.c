/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:07:25 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_command(t_shell *shell)
{
	shell->in_file_name = NULL;
	shell->file_name = NULL;
	if (parse_redirections(shell))
		exit((free_all(), exstat(-1)));
	if (handle_all_redir(shell))
		return ;
	if (shell->file_name)
	{
		shell->fd_out = ft_open(shell->file_name,
				O_CREAT | O_WRONLY | shell->red_mode, 0644);
		ft_dup2(shell->fd_out, 1);
	}
	if (shell->in_file_name)
	{
		shell->fd_in = ft_open(shell->in_file_name, O_RDONLY, 0);
		ft_dup2(shell->fd_in, 0);
	}
	if (is_builtin(*shell->cmd_and_args))
		execute_builtin_child(shell);
	else
		execute_command(shell);
}
