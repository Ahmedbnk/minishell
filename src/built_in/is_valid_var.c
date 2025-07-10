/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 06:02:14 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_var(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return ((p_err(buffering("export: `", str,
						"' : not a valid identifier\n")), 0));
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && str[i] != '_' && !ft_isdigit(str[i]))
			return ((p_err(buffering("export: `", str,
							"' : not a valid identifier\n")), 0));
		i++;
	}
	return (1);
}
