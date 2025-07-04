#include "minishell.h"

void	handle_append(char *str, char **file_name, t_shell_control_block *shell)
{
	int	fd;

	*file_name = str;
	fd = ft_open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
	{
		shell->exit_status = 1;
		return ;
	}
	ft_close(fd);
}
