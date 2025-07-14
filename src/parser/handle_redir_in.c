/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:10:48 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir_in(char *str, char **in_file_name, t_shell *shell)
{
	int	fd;
	DIR	*dir;

	shell = get_shell_pointer(NULL);
	*in_file_name = str;
	dir = opendir(*in_file_name);
	if (dir != NULL)
	{
		closedir(dir);
		exstat(0);
		return (0);
	}
	fd = ft_open(*in_file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		if (shell->cmd_and_args && !shell->cmd_and_args[0]
			&& shell->is_there_a_pipe)
			exstat(0);
		else
			exstat(1);
		return (1);
	}
	ft_close(fd);
	return (0);
}
