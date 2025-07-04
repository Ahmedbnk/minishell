/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_with_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:59 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**handle_dollar_with_quotes(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		if (are_they_equal(splitted[i], "<<"))
			i++;
		else
			splitted[i] = remove_dollar_if_quotes_after_it(splitted[i]);
		i++;
	}
	return (splitted);
}
