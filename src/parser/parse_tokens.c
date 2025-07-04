/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_tokens(t_shell_control_block *sh)
{
	char	**ptr;

	if (!sh || !sh->splitted)
		return ;
	ptr = sh->splitted;
	while (*ptr)
	{
		if (is_redirection(*ptr))
		{
			process_redirection_token(sh, ptr);
			ptr++;
		}
		else if (are_they_equal(*ptr, "|"))
			process_pipe_token(sh);
		ptr++;
	}
}
