#include "minishell.h"

char	*ft_getenv(void)
{
	char					**ptr;
	char					*value;
	int						start;
	int						end;
	int						i;
	t_shell_control_block	*shell_ptr;

	shell_ptr = get_shell_pointer(NULL);
	ptr = shell_ptr->env_cpy;
	i = 0;
	while (ptr[i])
	{
		if (compare_env_var(ptr[i], "PATH"))
		{
			get_start_and_end(ptr[i], &start, &end);
			value = ft_substr(ptr[i], start, (end - start));
			return (value);
		}
		i++;
	}
	return (NULL);
}
char	**get_path(void)
{
	char	*path;
	char	**splited;

	path = ft_getenv();
	splited = ft_split(path, ':');
	return (splited);
}
