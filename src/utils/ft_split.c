/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:02 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:02 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	int(i), (k), (start);
	if (!s)
		return (NULL);
	splitted = ft_malloc((ft_w_counter(s, c) + 1) * sizeof(char *), 1);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			splitted[k++] = ft_substr(s, start, i - start);
	}
	splitted[k] = NULL;
	return (splitted);
}
