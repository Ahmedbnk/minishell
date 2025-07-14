/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:14:35 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_pwd(void)
{
	int		status;
	char	*dir;

	dir = pwd(&status);
	if (dir != NULL)
	{
		printf("%s\n", dir);
		exstat(status);
	}
	else
		exstat(1);
}

static void	handle_exit(t_shell *shell)
{
	int	status;

	status = my_exit(shell->cmd_and_args + 1, shell);
	exstat(status);
	if (exstat(-1) != -1)
	{
		printf("exit\n");
		free_all();
		exit(exstat(-1));
	}
	else
		exstat(1);
}

void	execute_builtin_child(t_shell *shell)
{
	char	*cmd;

	cmd = *shell->cmd_and_args;
	if (are_eq(cmd, "pwd"))
		handle_pwd();
	else if (are_eq(cmd, "env"))
		exstat(print_env(*shell));
	else if (are_eq(cmd, "echo"))
		exstat(echo(shell->cmd_and_args));
	else if (are_eq(cmd, "cd"))
		exstat(cd(shell->env_cpy, shell->cmd_and_args));
	else if (are_eq(cmd, "export"))
		exstat(export(shell, shell->cmd_and_args + 1));
	else if (are_eq(cmd, "unset"))
		exstat(unset(&shell->env_cpy, shell->cmd_and_args + 1));
	else if (are_eq(cmd, "exit"))
		handle_exit(shell);
}
