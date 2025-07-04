/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char *str, int i)
{
	if (is_between_quotes(str, i))
		return (0);
	if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i
			+ 1] == '<'))
		return (2);
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		return (1);
	return (0);
}
