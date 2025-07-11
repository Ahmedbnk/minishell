/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/11 07:32:33 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_line(t_shell *sh)
{
	if (sh->tokenze)
	{
		create_all_heredocs(sh);
		get_cmd_and_its_args(sh);
		if (!is_there_a_pipe(sh) && is_builtin(*sh->cmd_and_args))
			execute_parent_builtin(sh);
		else
		{
			if (parse_redirections(sh) || sh->exit_status_flag)
				return ;
			execute_command_line(sh);
		}
	}
}
