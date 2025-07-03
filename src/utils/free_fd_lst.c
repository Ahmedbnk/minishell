#include "minishell.h"

void	free_fd_lst(void)
{
	int	*ptr;
	int	i;

	ptr = *(get_fd_pointer());
	i = 0;
	while (i < 1025)
	{
		if (ptr[i] == 1)
			close(i);
		i++;
	}
}
