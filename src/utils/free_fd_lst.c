#include "minishell.h"

int	is_std(int fd)
{
	return (fd == 0 || fd == 1 || fd == 2);
}
void	free_fd_lst(void)
{
	int	*ptr;
	int	i;

	ptr = *(get_fd_pointer());
	i = 0;
	while (i < 1025)
	{
		if (ptr[i] == 1 && !is_std(i))
			close(i);
		i++;
	}
}
