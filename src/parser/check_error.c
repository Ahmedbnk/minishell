/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:58 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:58 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error(t_shell_control_block *shell)
{
	char	*str;

	str = shell->line;
	if (!str || !*str)
		return (1);
	if (check_unclosed_quotes(str))
	{
		print(2, "unclosed quote\n");
		shell->exit_status = 2;
		return (1);
	}
	return (0);
}
