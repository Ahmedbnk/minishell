/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removed_file_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:35:51 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	removed_file_flag(int state)
{
	static int	value;

	if (state != -1)
		value = state;
	return (value);
}
