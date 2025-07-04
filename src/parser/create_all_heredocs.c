/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:59 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_all_heredocs(t_shell_control_block *shell)
{
	t_token	*ptr;

	shell->exit_status = 0;
	shell->exit_status_flag = 0;
	ptr = shell->tokenze;
	while (ptr)
	{
		if (shell->exit_status == 130)
			break ;
		if (ptr->type == HEREDOC)
			create_heredoc(shell, ptr);
		ptr = ptr->next;
	}
}
