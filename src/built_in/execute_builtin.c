/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 16:25:38 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(t_shell *shell)
{
	int	status;

	if (are_eq(*shell->cmd_and_args, "pwd"))
	{
		if (pwd(&status) != NULL)
		{
			printf("%s\n", pwd(&status));
			exstat(status);
		}
		else
			exstat(1);
	}
	else if (are_eq(*shell->cmd_and_args, "env"))
		exstat(print_env(shell->env_cpy));
	else if (are_eq(*shell->cmd_and_args, "echo"))
		exstat(echo(shell->cmd_and_args));
	else if (are_eq(*shell->cmd_and_args, "cd"))
		exstat(cd(shell->env_cpy, shell->cmd_and_args));
	else if (are_eq(*shell->cmd_and_args, "export"))
		exstat(export(shell, shell->cmd_and_args + 1));
	else if (are_eq(*shell->cmd_and_args, "unset"))
		exstat(unset(&shell->env_cpy, shell->cmd_and_args + 1));
	else if (are_eq(*shell->cmd_and_args, "exit"))
	{
		exstat(my_exit(shell->cmd_and_args + 1, shell));
		printf("the exit status is %d\n", exstat(-1));
		if (exstat(-1) != -1)
			exit((status = exstat(-1), free_all(), status));
		else
			exstat(1);
	}
}
