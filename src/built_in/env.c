/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:36:23 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(t_shell sh)
{
	char	**str;

	if (!sh.cmd_and_args || !sh.env_cpy)
		return (p_err("env: no environment variables \n"), 1);
	str = sh.env_cpy;
	if (sh.cmd_and_args[1])
		return ((p_err("env: no arguments allowed\n"), 1));
	while (*str)
		printf("%s\n", *str++);
	return (0);
}
