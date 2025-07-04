/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_lst(t_shell_control_block *sh)
{
	t_name_lst	*ptr;
	char		*str;

	if (!sh || !sh->file_name_lst)
		return ;
	ptr = sh->file_name_lst;
	while (ptr)
	{
		str = expand_if_possible(sh, ptr->file_name, 0);
		if (!*str)
		{
			ptr->status = AMBIGUOUS;
			ptr = ptr->next;
			continue ;
		}
		else
			handle_expansion_result(sh, ptr, str);
		ptr = ptr->next;
	}
}
