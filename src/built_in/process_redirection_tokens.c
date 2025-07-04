/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirection_tokens.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_redirection_tokens(t_shell_control_block *shell)
{
	if (shell->tokenze->type == HEREDOC)
		shell->in_file_name = shell->tokenze->heredoc_file_name;
	else if (shell->tokenze->type == REDIR_IN)
		handle_redir_in((shell->tokenze->next)->word, &(shell->in_file_name),
			shell);
	else if (shell->tokenze->type == REDIR_OUT)
		handle_redir_out((shell->tokenze->next)->word, &(shell->file_name),
			shell);
	else if (shell->tokenze->type == REDIR_APPEND)
		handle_append((shell->tokenze->next)->word, &(shell->file_name), shell);
	if (shell->exit_status)
		return (1);
	return (0);
}
