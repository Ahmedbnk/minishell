/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var_from_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_var_from_env(char ***env, char *var)
{
	char	**env_after_unset;
	int		i;

	i = 0;
	env_after_unset = ft_malloc(len_of_two_d_array(*env) * sizeof(char *), 0);
	while (**env)
	{
		if (!compare_env_var(**env, var))
			env_after_unset[i++] = ft_strdup(**env, 0);
		(*env)++;
	}
	env_after_unset[i] = NULL;
	*env = env_after_unset;
}
