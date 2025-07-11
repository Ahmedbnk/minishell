/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_there_a_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:02 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/11 21:24:29 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_there_a_pipe(t_shell *shell)
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
