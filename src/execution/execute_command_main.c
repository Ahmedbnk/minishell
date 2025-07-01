#include "minishell.h"

void	execute_command(t_shell_control_block *shell)
{
	char	**path;

	if (!*shell->cmd_and_args)
		return ;
	if (!**shell->cmd_and_args)
		exit((print_error("'%s' command not found\n", *shell->cmd_and_args),
				127));
	path = get_path();
	if (**shell->cmd_and_args == '/' || **shell->cmd_and_args == '.')
		check_the_access(*shell->cmd_and_args, shell->cmd_and_args,
			shell->env_cpy);
	else
		check_after_geting_path(*shell->cmd_and_args, shell->cmd_and_args, path,
			shell->env_cpy);
}
