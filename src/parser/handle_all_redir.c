/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_all_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/12 06:25:55 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_all_redir(t_shell *sh)
{
	while (sh->tokenze && sh->tokenze->word != NULL
		&& sh->tokenze->type != PIPE)
	{
		if (is_redirection(sh->tokenze->word) || are_eq(sh->tokenze->word,
				"<<"))
		{
			if (sh->tokenze->type == HEREDOC)
				sh->in_file_name = sh->tokenze->heredoc_file_name;
			else if (sh->tokenze->type == REDIR_IN
				&& handle_redir_in((sh->tokenze->next)->word,
					&(sh->in_file_name), sh))
				return (1);
			else if (sh->tokenze->type == REDIR_OUT
				&& handle_redir_out((sh->tokenze->next)->word, &(sh->file_name),
					sh))
				return (1);
			else if (sh->tokenze->type == REDIR_APPEND
				&& handle_append((sh->tokenze->next)->word, &(sh->file_name),
					sh))
				return (1);
		}
		sh->tokenze = sh->tokenze->next;
	}
	return (0);
}
