/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_readline(t_shell_control_block *sh)
{
	sh->line = readline("\001\033[1;31m\002Flash:\001\033[0m\002");
	if (sh->line && *sh->line)
		add_history(sh->line);
	if (sh->line == NULL)
	{
		free(sh->line);
		exit((free_all(), 0));
	}
	if (check_error(sh))
		return ((free(sh->line), NULL));
	return (sh->line);
}
