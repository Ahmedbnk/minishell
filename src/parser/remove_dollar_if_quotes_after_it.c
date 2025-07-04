/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dollar_if_quotes_after_it.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
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
		if (str[i] == '$' && !is_between_quotes(str, i) && (str[i
				+ 1] == single_q || str[i + 1] == double_q))
			i++;
		else
			returned_string[j++] = str[i++];
	}
	returned_string[j] = '\0';
	// remove_quotes(&returned_string);
	return (returned_string);
}
