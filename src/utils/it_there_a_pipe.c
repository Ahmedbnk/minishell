/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_there_a_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:02 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:02 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_there_a_pipe(t_shell_control_block *shell)
{
	t_token	*ptr;

	ptr = shell->tokenze;
	while (ptr)
	{
		if (ptr->type == PIPE)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
