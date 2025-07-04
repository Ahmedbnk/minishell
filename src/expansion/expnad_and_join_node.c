/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expnad_and_join_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:53 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:53 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expnad_and_join_node(t_shell_control_block *s, t_expand data)
{
	char	*path;
	char	*the_joined_node;
	char	*rest;

	if (data.to_expand != NULL)
	{
		if (are_they_equal(data.to_expand, "$?"))
		{
			path = ft_itoa(s->exit_status);
			// s->exit_status = 0;
		}
		else
			path = ft_strdup(get_env_var(s, data), 1);
		the_joined_node = custom_join(data.befor_dollar, path);
	}
	if (data.last_one)
	{
		rest = custom_join(the_joined_node, data.after_dollar);
		return (rest);
	}
	return (the_joined_node);
}
