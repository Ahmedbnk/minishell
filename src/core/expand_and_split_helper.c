/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_and_split_helper(t_shell_control_block *sh, int index)
{
	char	*ptr;

	ptr = expand_if_possible(sh, sh->splitted[index], 0);
	if (*ptr == 0)
	{
		add_token_to_lst(&sh->tokenze, new_token(ptr, -1));
		return ;
	}
	if (are_they_equal(sh->splitted[index], ptr))
	{
		rm_quotes_from_one_str(sh, &ptr);
		add_token_to_lst(&sh->tokenze, new_token(ptr, get_token_type(ptr)));
	}
	else
		split_after_expantion(sh, ptr, sh->splitted[index]);
}
