/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_after_geting_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:53 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 13:57:57 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	try_single_path(char *path, char *cmd, char **av, char **env)
{
	char	*cmd_with_its_path;
	char	*buffer;

	cmd_with_its_path = buf(path, "/", cmd);
	if (access(cmd_with_its_path, F_OK) == 0)
	{
		if (access(cmd_with_its_path, X_OK) == 0)
		{
			execve(cmd_with_its_path, av, env);
			buffer = buf(buf(cmd, ": ", 0), buf(strerror(errno), "\n", 0),
					0);
			exit((p_err(buffer), free_all(), errno));
		}
		else
			return (1);
	}
	return (0);
}


void	check_after_geting_path(char *cmd, char **av, char **path, char **env)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (path[i])
	{
		if (try_single_path(path[i], cmd, av, env))
			flag = 1;
		i++;
	}
	if (flag)
		exit((p_err(buf(cmd, ": ", "Permission denied\n")), free_all(), 126));
	exit((p_err(buf(cmd, ": ", "command not found\n")), free_all(), 127));
}
