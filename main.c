/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:50:42 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/13 13:10:06 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	is_std_fd_closed(void)
{
	if (!isatty(0))
		return (1);
	if (!isatty(1))
		return ((p_err("Please open standard FDs before runing minishell\n"),
				1));
	if (!isatty(2))
		return ((p_err("Please open standard FDs before runing minishell\n"),
				1));
	return (0);
}

int	exstat(int n)
{
	static int	exit_status;

	if (n != -1)
		exit_status = n;
	return (exit_status);
}

int	main(int ac, char **av, char **env)
{
	t_shell	sh;
	char	*buffer;

	if (is_std_fd_closed())
		return (1);
	buffer = ft_malloc(SIZE, 0);
	removed_file_flag(getcwd(buffer, SIZE) == NULL);
	ft_init_shell_block(&sh, ac, av);
	sh.env_of_export = copy_2d(env, 0);
	sh.env_cpy = copy_2d(env, 0);
	get_shell_pointer(&sh);
	handle_signals();
	while (1)
	{
		sh.is_there_a_pipe = 0;
    sh.out_or_append = 0;
		make_fd_lst();
		set_handler_state(0);
		if (!ft_readline(&sh) || parse_line(&sh) || !is_there_a_char(sh.line))
			continue ;
		expand_and_split(&sh);
		sh.is_there_a_pipe = is_there_a_pipe(&sh);
		execute_line(&sh);
		free_fd_lst();
		free_memory(get_garbage_pointer(1));
		free(sh.line);
	}
	return (0);
}
