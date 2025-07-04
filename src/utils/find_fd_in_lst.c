
#include "minishell.h"

int	find_fd_in_lst(int fd)
{
	int	*ptr;

	ptr = *(get_fd_pointer());
	return (ptr[fd] == 1);
}
