/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_from_one_str_helper.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_quotes_from_one_str_helper(t_shell_control_block *sh, char *line,
		char **parsed_quote_line)
{
	int		i;
	int		j;
	char	quote;

	(void)sh;
	i = 0;
	j = 0;
	quote = 0;
	while (line[i])
	{
		if (is_quote(line[i]) && quote == 0 && !is_protected(sh, line, i))
			quote = line[i];
		else if (is_quote(line[i]) && quote == line[i])
			quote = 0;
		else
			(*parsed_quote_line)[j++] = line[i];
		if (is_quote(line[i]) && is_protected(sh, line, i))
			i = (i + ft_strlen(sh->porotect_var));
		i++;
	}
	(*parsed_quote_line)[j] = '\0';
}
