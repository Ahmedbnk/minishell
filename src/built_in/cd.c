/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:51:18 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/10 06:02:14 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char **env, char **path)
{
	char	*new_dir;
	int		status;
	int		len;
	char	*buffer;

	buffer = ft_malloc(SIZE, 1);
	status = 0;
	len = len_of_two_d_array(path);
	if (len > 2)
		return (p_err(" too many arguments\n"), 1);
	if (are_eq(*path, "cd"))
		path++;
	if (!*path)
		chdir(ft_getenv("HOME"));
	else
		chdir(*path);
	removed_file_flag(0);
	if (getcwd(buffer, SIZE) == NULL)
		p_err(CD_ERROR);
	new_dir = pwd(&status);
	update_env_dir(env, ft_getenv("PWD"), new_dir);
	return (0);
}
