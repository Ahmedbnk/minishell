#include "minishell.h"

void	create_heredoc(t_shell_control_block *s, t_token *tokenze)
{
	int		fd;
	char	*str;
	char	*buffer;
	int		has_qoutes;
	int		rc;
	int		status;

	str = NULL;
	buffer = NULL;
	tokenze->heredoc_file_name = ft_strjoin("/tmp/", generate_random_name());
	tokenze->delimiter = tokenze->next->word;
	has_qoutes = does_it_has_qoutes(tokenze->delimiter);
	rm_quotes_from_one_str(s, &(tokenze->delimiter));
	signal(SIGINT, SIG_IGN);
	set_handler_state(1);
	rc = fork();
	if (rc == 0)
	{
		handle_signals();
		while (1)
		{
			str = readline("> ");
			if (str == NULL)
			{
				exit((print(2,
							buffering("warning: here-document delimited by end-of-file wanted: ",
								tokenze->delimiter, "\n")), free_all(), 0));
			}
			if (are_they_equal(str, tokenze->delimiter))
				break ;
			if (!has_qoutes)
				str = expand_if_possible(s, str, 1);
			buffer = ft_strjoin(buffer, ft_strjoin(str, "\n"));
		}
		fd = ft_open(tokenze->heredoc_file_name, O_CREAT | O_RDWR | O_TRUNC,
				0644);
		write(fd, buffer, ft_strlen(buffer));
		ft_close(fd);
		exit((free_all(), 0));
	}
	else
	{
		waitpid(rc, &status, 0);
		if (WIFEXITED(status))
			s->exit_status = WEXITSTATUS(status);
		if (s->exit_status == 130)
			s->exit_status_flag = 1;
		handle_signals();
	}
}
