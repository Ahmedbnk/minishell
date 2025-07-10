/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_all_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 18:48:55 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_all_redir(t_shell *shell)
{
	while (shell->tokenze && shell->tokenze->word != NULL
		&& shell->tokenze->type != PIPE)
	{
		if (is_redirection(shell->tokenze->word) || are_eq(shell->tokenze->word,
				"<<"))
		{
			if (shell->tokenze->type == HEREDOC)
				shell->in_file_name = shell->tokenze->heredoc_file_name;
			else if (shell->tokenze->type == REDIR_IN)
				handle_redir_in((shell->tokenze->next)->word,
					&(shell->in_file_name), shell);
			else if (shell->tokenze->type == REDIR_OUT)
				handle_redir_out((shell->tokenze->next)->word,
					&(shell->file_name), shell);
			else if (shell->tokenze->type == REDIR_APPEND)
				handle_append((shell->tokenze->next)->word, &(shell->file_name),
					shell);
			if (exstat(-1))
				return (1);
		}
		shell->tokenze = shell->tokenze->next;
	}
	return (0);
}
