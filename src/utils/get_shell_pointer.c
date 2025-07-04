/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shell_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:03 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:53:03 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell_control_block	*get_shell_pointer(t_shell_control_block *ptr)
{
	static t_shell_control_block	*pointer_to_ptr;

	if (ptr)
		pointer_to_ptr = ptr;
	return (pointer_to_ptr);
}
