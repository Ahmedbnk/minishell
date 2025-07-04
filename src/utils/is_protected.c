/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_protected.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:02 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:02 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_protected(t_shell_control_block *sh, char *str, int index)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = sh->porotect_var;
	i = 0;
	index += 1;
	len = ft_strlen(ptr);
	while (i < len)
	{
		if (str[index] != ptr[i])
			return (0);
		index++;
		i++;
	}
	return (1);
}
