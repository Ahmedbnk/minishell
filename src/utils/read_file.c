#include "minishell.h"

char	*read_file(char *file_name)
{
	char	*small_buffer;
	char	*big_buffer;
	int		fd;

	big_buffer = NULL;
	fd = ft_open(file_name, O_RDWR, 0777);
	if (fd < 0)
		return (NULL);
	small_buffer = get_next_line(fd);
	while (small_buffer)
	{
		big_buffer = ft_strjoin(big_buffer, small_buffer);
		small_buffer = get_next_line(fd);
	}
	ft_close(fd);
	return (big_buffer);
}
