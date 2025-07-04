/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_and_split(t_shell_control_block *sh)
{
	int	i;

	i = 0;
	sh->tokenze = NULL;
	while (sh->splitted[i])
	{
		if (are_they_equal(sh->splitted[i], "<<"))
		{
			add_token_to_lst(&sh->tokenze, new_token(sh->splitted[i],
					get_token_type(sh->splitted[i])));
			i++;
			add_token_to_lst(&sh->tokenze, new_token(sh->splitted[i],
					get_token_type(sh->splitted[i])));
		}
		else
			expand_and_split_helper(sh, i);
		i++;
	}
}
