#include "minishell.h"

// static int	find_fd_in_lst(fd)
// {
// 	int	*ptr;

// 	ptr = *(get_fd_pointer());
// 	return (ptr[fd] == 1);
// }

void	ft_close(int fd)
{
	if (fd < 0)
		return ;
	// if (find_fd_in_lst(fd))
	close(fd);
}
