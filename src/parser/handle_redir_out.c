/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:59 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/13 13:02:31 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir_out(char *str, char **file_name, t_shell *shell)
{
	int	fd;

	*file_name = str;
	fd = ft_open(str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return ((exstat(1), 1));
	shell->red_mode = O_TRUNC;
	ft_close(fd);
	return (0);
}
