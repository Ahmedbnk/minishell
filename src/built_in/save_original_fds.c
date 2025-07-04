/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_original_fds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_original_fds(t_shell_control_block *shell)
{
	shell->original_stdin = ft_dup(0);
	shell->original_stdout = ft_dup(1);
}
