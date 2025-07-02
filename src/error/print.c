#include "minishell.h"

void	print(int fd, char *str)
{
	size_t	size;

	size = ft_strlen(str);
	write(fd, str, size);
}
