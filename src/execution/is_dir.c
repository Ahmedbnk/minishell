/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:28:17 by nkasimi           #+#    #+#             */
/*   Updated: 2025/07/14 10:18:25 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dir(char *cmd)
{
	DIR	*ptr;

	if (!cmd)
		return (0);
	ptr = opendir(cmd);
	if (ptr != NULL)
	{
		closedir(ptr);
		exe_flag(IS_DIR);
		return (1);
	}
	return (0);
}
