/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_pipe_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:01 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 06:02:14 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_pipe_syntax(char **splitted, int i)
{
	if (i == 0 || !splitted[i + 1])
		return (p_err("syntax error near unexpected str `|'\n"), 1);
	if (is_red_symbole(splitted[i - 1]) || is_pipe(splitted[i - 1]))
		return (p_err("syntax error near unexpected str `|'\n"), 1);
	return (0);
}
