/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 16:57:40 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_all_heredocs(t_shell *shell)
{
	t_token	*ptr;

	// exstat(0);
	// s(ft_itoa(exstat(-1)));
	shell->exit_status_flag = 0;
	ptr = shell->tokenze;
	while (ptr)
	{
		if (exstat(-1) == 130)
			break ;
		if (ptr->type == HEREDOC)
			create_heredoc(shell, ptr);
		ptr = ptr->next;
	}
}
