/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 08:36:54 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_exit(char **args)
{
	long long	result;

	if (len_of_two_d_array(args) == 0)
		return (0);
	result = 0;
	if (!check_is_valid_number(*args))
	{
		p_err(buf("exit: ", *args, ": numeric argument required\n"));
		return (2);
	}
	else if (*(args + 1))
	{
		p_err("exit: too many arguments\n");
		return (1);
	}
	result = ft_atol(*args);
	return ((int)(result % 256));
}
