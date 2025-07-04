/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:53 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:53 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_shell_control_block *shell)
{
	char	**path;
	char	**cmds;
	char	*buffer;

	cmds = shell->cmd_and_args;
	if (!*cmds)
		return ;
	buffer = buffering(buffering("'", *cmds, "'"), " command not found\n", 0);
	if (!**cmds)
		exit((print(2, buffer), free_all(), 127));
	path = get_path();
	if (**cmds == '/' || **cmds == '.')
		check_the_access(*cmds, cmds, shell->env_cpy);
	else
	{
		if (path == NULL)
			exit((print(2, buffering(*shell->cmd_and_args, ": ",
							"No such file or directory\n")), free_all(), 127));
		check_after_geting_path(*cmds, cmds, path, shell->env_cpy);
	}
}
