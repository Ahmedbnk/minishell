/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_ambig_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_ambig_list(t_shell_control_block *shell)
{
	t_name_lst	*name_lst;

	name_lst = shell->file_name_lst;
	if (!name_lst)
		return ;
	while (name_lst != NULL && name_lst->status != NEW_START)
		name_lst = name_lst->next;
	if (name_lst != NULL && name_lst->status == NEW_START)
		name_lst = name_lst->next;
	shell->file_name_lst = name_lst;
}
