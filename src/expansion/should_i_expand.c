/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_i_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:54 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:54 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	should_i_expand(char *str, int index)
{
	char	quote;

	quote = 0;
	quote = is_between_quotes(str, index);
	if (quote == single_q || str[index + 1] == '\0' || str[index
		+ 1] == single_q || str[index + 1] == double_q)
		return (0);
	else
		return (1);
}
