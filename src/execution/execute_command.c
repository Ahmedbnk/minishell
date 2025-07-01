#include "minishell.h"

void	execute_command(t_shell_control_block *shell)
{
	char	**path;
	char	**cmds;

	cmds = shell->cmd_and_args;
	if (!*cmds)
		return ;
	if (!**cmds)
		exit((print_error("'%s' command not found\n", *cmds), 127));
	if (opendir(*cmds) != NULL)
		exit((print_error("%s: Is a directory\n", *cmds), 126));
	path = get_path();
	if (**cmds == '/' || **cmds == '.')
		check_the_access(*cmds, cmds, shell->env_cpy);
	else
	{
		if (path == NULL)
			exit((print_error("%s: No such file or directory\n", *shell->cmd_and_args),
					127));
		check_after_geting_path(*cmds, cmds, path, shell->env_cpy);
	}
}
