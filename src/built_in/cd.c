/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:51:18 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:51:18 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char **env, char **path)
{
	char	*old_dir;
	char	*new_dir;
	int		status;
	int		len;

	status = 0;
	len = len_of_two_d_array(path);
	if (len > 2)
		return (print(2, " too many arguments\n"), 1);
	if (are_they_equal(*path, "cd"))
		path++;
	old_dir = pwd(&status);
	if (chdir(*path) == 0)
	{
		new_dir = pwd(&status);
		update_env_dir(env, old_dir, new_dir);
	}
	else
		return (print(2, buffering(" ", strerror(errno), "\n")), 1);
	return (0);
}
