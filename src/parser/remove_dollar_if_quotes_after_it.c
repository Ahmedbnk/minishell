/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dollar_if_quotes_after_it.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:09:29 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_dollar_if_quotes_after_it(char *str)
{
	char	*returned_string;
	int		i;
	int		j;

	returned_string = ft_malloc(ft_strlen(str) + 1, 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && !is_between_quotes(str, i) && is_quote(str[i + 1]))
			i++;
		else
			returned_string[j++] = str[i++];
	}
	returned_string[j] = '\0';
	return (returned_string);
}
