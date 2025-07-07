/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/07 21:11:09 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redir_in(char *str, char **in_file_name, t_shell *shell)
{
	char	*buffer;
	int		fd;

	shell = get_shell_pointer(NULL);
	buffer = NULL;
	*in_file_name = str;
	fd = ft_open(*in_file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		if (is_there_a_pipe(shell))
			shell->exit_status = -1;
		else
			shell->exit_status = 1;
		return ;
	}
	buffer = read_file(str);
	if (!buffer)
		return ;
	write(fd, buffer, ft_strlen(buffer));
	ft_close(fd);
}
