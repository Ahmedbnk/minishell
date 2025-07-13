/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/13 10:56:59 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_append(char *str, char **file_name, t_shell *shell)
{
	int	fd;

	(void)shell;
	*file_name = str;
  shell->out_or_append = REDIR_APPEND;
	fd = ft_open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		return ((exstat(1), 1));
	shell->red_mode = O_APPEND;
	ft_close(fd);
	return (0);
}
