/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_red_symbole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:00 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:00 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_red_symbole(char *str)
{
	if (!str)
		return (0);
	if (are_they_equal(str, "<") || are_they_equal(str, ">"))
		return (1);
	if (are_they_equal(str, ">>") || are_they_equal(str, "<<"))
		return (1);
	return (0);
}
