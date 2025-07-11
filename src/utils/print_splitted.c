/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_splitted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:03 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/11 11:22:22 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_splitted(char **splitted)
{
	int	i;

	if (!splitted || !*splitted)
		return ;
	i = 0;
	while (splitted[i])
	{
		printf("%s\n", splitted[i]);
		i++;
	}
}
