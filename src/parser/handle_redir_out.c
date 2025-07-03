#include "minishell.h"

void	handle_redir_out(char *str, char **file_name, t_shell_control_block *shell)
{
	int	fd;

	*file_name = str;
	fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0644);
  if(fd < 0)
  {
    perror(*file_name);
    shell->exit_status = 1;
    return;
  }
	ft_close(fd);
}
