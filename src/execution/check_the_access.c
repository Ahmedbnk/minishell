#include "minishell.h"

void	check_the_access(char *cmd, char **av, char **env)
{
	char	*buffer;

	if (opendir(cmd) != NULL)
		exit((print(2, buffering(cmd, ": ", "Is a directory\n")), 126));
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, av, env);
			buffer = buffering(buffering(cmd, ": ", 0),
					buffering(strerror(errno), "\n", 0), 0);
			exit((print(2, buffer), errno));
		}
		else
			exit((print(2, buffering(cmd, ": ", "Permition denied\n")), 126));
	}
	else if (*cmd == '/' || *cmd == '.')
		exit((print(2, buffering(cmd, ": ", "No such file or directory \n")),
				127));
}
