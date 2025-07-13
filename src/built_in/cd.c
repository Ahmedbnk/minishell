/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:51:18 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/13 05:32:00 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char *correct_path(char *str)
// {
// 	if()
// }
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
	else if (chdir(*path) != 0)
		return ((exstat(1), perror(*path), 1));
	removed_file_flag(0);
	if (getcwd(buffer, SIZE) == NULL)
		p_err(CD_ERROR);
	new_dir = pwd(&status);
	update_env_dir(env, ft_getenv("PWD"), new_dir);
	return (0);
}
