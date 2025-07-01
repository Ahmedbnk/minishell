#include "minishell.h"

void	check_the_access(char *cmd, char **av, char **env)
{
	if (opendir(cmd) != NULL)
  {
		exit((print_error("%s: Is a directory\n", cmd), 126));
  }
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, av, env);
			exit((print_error("%s: %s\n", cmd, strerror(errno)), errno));
		}
		else
			exit((print_error("%s: Permition denied\n", cmd), 126));
	}
	else if (*cmd == '/' || *cmd == '.')
		exit((print_error("%s: No such file or directory \n", cmd), 127));
}
