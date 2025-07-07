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

int	is_dir(char *cmd)
{
	DIR	*ptr;

	if (!cmd)
		return (0);
	if ((ptr = opendir(cmd)) != NULL)
		exit((closedir(ptr), print(2, buffering(cmd, ": ", "Is a directory\n")),
				free_all(), 126));
	return (0);
}

void	check_the_access(char *cmd, char **av, char **env)
{
	char	*buffer;

	is_dir(cmd);
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, av, env);
			buffer = buffering(buffering(cmd, ": ", 0),
					buffering(strerror(errno), "\n", 0), 0);
			exit((print(2, buffer), free_all(), errno));
		}
		else
			exit((print(2, buffering(cmd, ": ", "Permission denied\n")),
					free_all(), 126));
	}
	else if (*cmd == '/' || *cmd == '.')
		exit((print(2, buffering(cmd, ": ", "No such file or directory\n")),
				free_all(), 127));
}
