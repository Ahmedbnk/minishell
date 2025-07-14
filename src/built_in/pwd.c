/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 06:02:14 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pwd(int *status)
{
	char	*str;
	char	*buffer;

	str = ft_getenv("PWD");
	*status = 0;
	if (removed_file_flag(-1))
	{
		p_err(PWD_ERROR);
		*status = 1;
		return (NULL);
	}
	buffer = ft_malloc(SIZE, 1);
	if (getcwd(buffer, SIZE) != NULL)
		return (buffer);
	else if (str)
		return (str);
	return (NULL);
}
