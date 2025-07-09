/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:01 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/09 11:00:01 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_fd_to_lst(int fd)
{
	int	*ptr;

	if (fd < 0 || fd > 1024)
		return ;
	ptr = *(get_fd_pointer());
	if (!ptr)
		return ;
	if (ptr[fd] == -1)
		ptr[fd] = 1;
}

int	ft_open(const char *pathname, int flags, mode_t mode)
{
	int	fd;

	if (!pathname)
		return ((errno = EFAULT, -1));
	fd = open(pathname, flags, mode);
	if (fd < 0 && )
		perror(pathname);
	else
		add_fd_to_lst(fd);
	return (fd);
}
