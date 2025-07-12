/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/12 06:53:19 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir_in(char *str, char **in_file_name, t_shell *shell)
{
	char	*buffer;
	int		fd;

	shell = get_shell_pointer(NULL);
	buffer = NULL;
	*in_file_name = str;
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
	buffer = read_file(str);
	if (!buffer)
		return (0);
	write(fd, buffer, ft_strlen(buffer));
	ft_close(fd);
	return (0);
}
