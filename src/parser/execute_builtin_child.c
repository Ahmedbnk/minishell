#include "minishell.h"

void	execute_builtin_child(t_shell_control_block *shell)
{
	int	status;

	if (are_they_equal(*shell->cmd_and_args, "pwd"))
	{
		printf("%s\n", pwd(&status));
		exit(status);
	}
	else if (are_they_equal(*shell->cmd_and_args, "env"))
		exit(print_env(shell->env_cpy));
	else if (are_they_equal(*shell->cmd_and_args, "echo"))
		exit(echo(shell->cmd_and_args));
	else if (are_they_equal(*shell->cmd_and_args, "cd"))
		exit(cd(shell->env_cpy, shell->cmd_and_args));
	else if (are_they_equal(*shell->cmd_and_args, "export"))
		exit(export(shell, shell->cmd_and_args + 1));
	else if (are_they_equal(*shell->cmd_and_args, "unset"))
		exit(unset(&shell->env_cpy, shell->cmd_and_args + 1));
	else if (are_they_equal(*shell->cmd_and_args, "exit"))
  {
		shell->exit_status =my_exit(shell->cmd_and_args + 1);
    if(shell->exit_status != 1)
      exit(shell->exit_status);
  }
}
