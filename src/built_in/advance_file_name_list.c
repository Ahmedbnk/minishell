/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_file_name_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:51:16 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:51:16 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	advance_file_name_list(t_shell_control_block *shell)
{
	if (shell->file_name_lst)
		shell->file_name_lst = shell->file_name_lst->next;
}
