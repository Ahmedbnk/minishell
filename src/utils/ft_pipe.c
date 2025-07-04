#include "minishell.h"

int	ft_pipe(int pipefd[2])
{
	int	result;

	result = pipe(pipefd);
	if (result == 0)
	{
		add_fd_to_lst(pipefd[0]);
		add_fd_to_lst(pipefd[1]);
	}
	return (result);
}
