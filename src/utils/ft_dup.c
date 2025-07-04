#include "minishell.h"

int	ft_dup(int oldfd)
{
	int	newfd;

	newfd = dup(oldfd);
	if (newfd >= 0)
		add_fd_to_lst(newfd);
	return (newfd);
}

int	ft_dup2(int oldfd, int newfd)
{
	int	result;

	if (find_fd_in_lst(newfd))
		ft_close(newfd);
	result = dup2(oldfd, newfd);
	if (result >= 0)
		add_fd_to_lst(newfd);
	return (result);
}
