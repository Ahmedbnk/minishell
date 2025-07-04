/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_from_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_quotes_from_one_str(t_shell_control_block *sh, char **line)
{
	char	*line_without_quotes;

	line_without_quotes = ft_malloc(ft_strlen(*line) + 1, 1);
	rm_quotes_from_one_str_helper(sh, *line, &line_without_quotes);
	*line = line_without_quotes;
}
