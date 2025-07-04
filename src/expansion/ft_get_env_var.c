/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:53 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:53 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_shell_control_block *shell, t_expand data)
{
	char	**ptr;
	char	*value;
	int		start;
	int		end;
	int		i;

	ptr = shell->env_cpy;
	i = 0;
	while (ptr[i])
	{
		if (compare_env_var(ptr[i], (data.to_expand) + 1))
		{
			get_start_and_end(ptr[i], &start, &end);
			value = ft_substr(ptr[i], start, (end - start));
			value = protect_str(shell, value);
			return (value);
		}
		i++;
	}
	return (NULL);
}
