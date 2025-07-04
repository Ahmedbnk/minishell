/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_after_expantion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 18:23:29 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_after_expantion(t_shell *sh, char *str,
		char *old_str)
{
	int		i;
	char	**ptr;

	i = 0;
	if (!*str || is_there_invalid_expantion(sh, str, old_str))
		return ;
	ptr = customized_split(str);
	while (ptr[i])
	{
		rm_quotes_from_one_str(sh, &ptr[i]);
		add_token_to_lst(&sh->tokenze, new_token(ptr[i], WORD));
		i++;
	}
}
