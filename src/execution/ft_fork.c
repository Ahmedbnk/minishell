/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:32:00 by nkasimi           #+#    #+#             */
/*   Updated: 2025/07/14 14:32:01 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_array_of_pids(void)
{
	static int	*arr;
	int			i;

	if (!arr)
	{
		i = 0;
		arr = ft_malloc(sizeof(int) * MAX_NUM_OF_PROC, 1);
		while (i < MAX_NUM_OF_PROC)
		{
			arr[i] = 0;
			i++;
		}
	}
	return (arr);
}

void	add_pid_to_array(int p_id)
{
	int	*arr;
	int	i;

	arr = get_array_of_pids();
	i = 0;
	while (i < MAX_NUM_OF_PROC && arr[i] != 0)
		i++;
	if (i < MAX_NUM_OF_PROC)
		arr[i] = p_id;
}

void	kill_all(void)
{
	int	*arr;
	int	i;

	arr = get_array_of_pids();
	i = 0;
	while (i < MAX_NUM_OF_PROC && arr[i] != 0)
	{
		kill(arr[i], SIGKILL);
		i++;
	}
}

int	ft_fork(void)
{
	int	p_id;

	p_id = fork();
	if (p_id < 0)
	{
		p_err("Fork failed");
		exit((kill_all(), free_all(), 1));
	}
	add_pid_to_array(p_id);
	return (p_id);
}
