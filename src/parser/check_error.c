/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:58 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 16:31:07 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error(t_shell *shell)
{
	char	*str;

	str = shell->line;
	if (!str || !*str)
		return (1);
	if (check_unclosed_quotes(str))
	{
		p_err("unclosed quote\n");
		exstat(2);
		return (1);
	}
	return (0);
}
