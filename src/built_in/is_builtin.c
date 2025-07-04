/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:51 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:51 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *str)
{
	if (are_they_equal(str, "pwd") || are_they_equal(str, "env")
		|| are_they_equal(str, "cd") || are_they_equal(str, "echo")
		|| are_they_equal(str, "export") || are_they_equal(str, "unset")
		|| are_they_equal(str, "exit"))
		return (1);
	return (0);
}
