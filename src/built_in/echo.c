/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:51 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **args)
{
	int	new_line_flag;

	args++;
	new_line_flag = 0;
	if (is_valid_flag(*args))
	{
		new_line_flag = 1;
		args++;
	}
	while (*args)
	{
		printf("%s", *args);
		if (*(args + 1) != NULL)
			printf(" ");
		args++;
	}
	if (!new_line_flag)
		printf("\n");
	return (0);
}
