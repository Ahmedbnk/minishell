/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambiguous_redirection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:51:19 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 16:26:39 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_ambiguous_redirection(t_shell *shell)
{
	if (shell->file_name_lst && shell->file_name_lst->status == AMBIGUOUS)
	{
		p_err("ambig\n");
		exstat(1);
		return (1);
	}
	return (0);
}
