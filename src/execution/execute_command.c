/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:53 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/11 06:54:03 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	is_dir(char *cmd)
// {
// 	DIR	*ptr;

// 	if (!cmd)
// 		return (0);
// 	if ((ptr = opendir(cmd)) != NULL)
// 		exit((closedir(ptr), p_err(buf(cmd, ": ", "Is a directory\n")),
// 				free_all(), 126));
// 	return (0);
// }

int	has_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	execute_command(t_shell *shell)
{
	char	**path;
	char	**cmds;
	char	*buffer;

	cmds = shell->cmd_and_args;
	if (!*cmds)
		return ;
	buffer = buf(buf("'", *cmds, "'"), " command not found\n", 0);
	if (!**cmds)
		exit((p_err(buffer), free_all(), 127));
	is_dir(*cmds);
	path = get_path();
	free_fd_lst();
	if (has_slash(*cmds))
		check_the_access(*cmds, cmds, shell->env_cpy);
	else
	{
		if (!*path)
			exit((p_err(buf(*shell->cmd_and_args, ": ",
							"No such file or directory\n")), free_all(), 127));
		check_after_geting_path(*cmds, cmds, path, shell->env_cpy);
	}
}
