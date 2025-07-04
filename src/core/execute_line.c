/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_line(t_shell_control_block *sh)
{
	if (sh->tokenze)
	{
		create_all_heredocs(sh);
		get_cmd_and_its_args(sh);
		if (!is_there_a_pipe(sh) && is_builtin(*sh->cmd_and_args))
			execute_parent_builtin(sh);
		else
			execute_command_line(sh);
	}
}
