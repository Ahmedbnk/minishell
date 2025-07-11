/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/11 09:43:25 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_readline(t_shell *sh)
{
	read_history(".minishell_history");
	sh->line = readline("\001\033[1;31m\002Flash:\001\033[0m\002");
	if (sh->line && *sh->line && is_there_a_char(sh->line))
		add_history(sh->line);
	if (sh->line == NULL)
	{
		free(sh->line);
		write_history(".minishell_history");
		exit((free_all(), exstat(-1)));
	}
	write_history(".minishell_history");
	if (check_error(sh))
		return ((free(sh->line), NULL));
	return (sh->line);
}
