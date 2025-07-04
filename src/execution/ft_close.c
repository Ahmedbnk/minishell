#include "minishell.h"

void	ft_close(int fd)
{
	int	*ptr;

	ptr = *(get_fd_pointer());
	if (fd < 0)
		return ;
	if (ptr[fd] == 1)
		close(fd);
	ptr[fd] = -1;
}
