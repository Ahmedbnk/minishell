/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_output_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/13 13:17:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_output_redirection(t_shell *shell)
{
  int fd;
  fd = 0;
	if (shell->file_name)
	{
		shell->original_stdout = ft_dup(1);
		if (shell->out_or_append == REDIR_OUT)
      fd = ft_open(shell->file_name, O_TRUNC | O_CREAT | O_WRONLY,0644);
    else
      fd = ft_open(shell->file_name, O_APPEND | O_CREAT | O_WRONLY, 0644);
    ft_dup2(fd, 1);
	}
}
