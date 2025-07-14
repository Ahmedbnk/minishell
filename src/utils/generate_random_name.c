/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:02 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:04:14 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	generate_random_number(void)
{
	int	fd;
	int	random_number;

	fd = ft_open("/dev/random", O_RDONLY, 0);
	read(fd, &random_number, 4);
	ft_close(fd);
	if (random_number < 0)
		return (-random_number);
	return (random_number);
}

char	*generate_random_name(void)
{
	int	num;

	num = generate_random_number();
	if (num < 0)
		return (NULL);
	return (ft_itoa(num));
}
