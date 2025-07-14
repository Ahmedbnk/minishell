/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:01 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/14 09:09:59 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_heredoc_file(char *file_name, char *buffer)
{
	int	fd;

	fd = ft_open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(fd, buffer, ft_strlen(buffer));
	ft_close(fd);
}

void	wait_heredoc_child(t_shell *s, int pid)
{
	int	status;

	(void)s;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exstat(WEXITSTATUS(status));
	if (exstat(-1) == 130)
		s->exit_status_flag = 1;
	handle_signals();
}

void	handle_heredoc_child(t_shell *s, t_token *tokenze, int has_qoutes)
{
	char	*str;
	char	*buffer;
	char	*ctrl_d_msg;

	ctrl_d_msg = "warning: here-document delimited by end-of-file wanted: ";
	str = NULL;
	buffer = NULL;
	handle_signals();
	while (1)
	{
		str = readline("> ");
		if (str == NULL)
		{
			write_heredoc_file(tokenze->heredoc_file_name, buffer);
			exit((p_err(buf(ctrl_d_msg, tokenze->delimiter, "\n")), free_all(),
					0));
		}
		if (are_eq(str, tokenze->delimiter))
			break ;
		if (!has_qoutes)
			str = expand_if_possible(s, str, 1);
		buffer = ft_strjoin(buffer, ft_strjoin(str, "\n"));
	}
	write_heredoc_file(tokenze->heredoc_file_name, buffer);
	exit((free_all(), 0));
}

void	create_heredoc(t_shell *s, t_token *tokenze)
{
	int	rc;
	int	has_qoutes;

	tokenze->heredoc_file_name = ft_strjoin("/tmp/", generate_random_name());
	tokenze->delimiter = tokenze->next->word;
	has_qoutes = does_it_has_qoutes(tokenze->delimiter);
	rm_quotes_from_one_str(s, &(tokenze->delimiter));
	signal(SIGINT, SIG_IGN);
	set_handler_state(1);
	rc = ft_fork();
	if (rc == 0)
		handle_heredoc_child(s, tokenze, has_qoutes);
	else
		wait_heredoc_child(s, rc);
}
