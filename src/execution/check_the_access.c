/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:53 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/07 10:07:21y nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_the_access(char *cmd, char **av, char **env)
{
	char	*buffer;

	if (is_dir(cmd))
	{
		buffer = buf(buf(cmd, ": ", "Is a directory\n"), 0, 0);
		exit((p_err(buffer), free_all(), 126));
	}
	if (access(cmd, X_OK) == 0)
	{
		s("execve");
		execve(cmd, av, env);
		buffer = buf(buf(cmd, ": ", 0), buf(strerror(errno), "\n", 0), 0);
		exit((p_err(buffer), free_all(), errno));
	}
	if (errno == 13)
		exit((p_err(buf(cmd, ": ", "Permission denied\n")), free_all(), 126));
	else if (errno == 20)
		exit((p_err(buf(cmd, ": Not a directory\n", 0)), free_all(), 126));
	exit((perror(cmd), free_all(), errno));
}
