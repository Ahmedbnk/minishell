#include "minishell.h"

char	*join_args(char *s1, char *s2, char *s3)
{
	char	*first_join;
	char	*second_join;

	first_join = custom_join(s1, s2);
	second_join = custom_join(first_join, s3);
	return (second_join);
}

char	*add_new_line(char *str)
{
	char	*str_with_new_line;

	return (str_with_new_line = custom_join(str, "\n"));
}

void	print(int fd, char *str)
{
	size_t	size;

	size = ft_strlen(str);
	write(fd, str, size);
}
