#include "minishell.h"

void	check_after_geting_path(char *cmd, char **av, char **path, char **env)
{
	int		i;
	char	*cmd_with_slash;
	char	*cmd_with_its_path;

	if (!path)
	{
		printf("%s\n", cmd);
		printf("No such file or directory\n");
		return ;
	}
	i = 0;
	cmd_with_slash = ft_strjoin("/", cmd);
	while (path[i])
	{
		cmd_with_its_path = ft_strjoin(path[i], cmd_with_slash);
		if (access(cmd_with_its_path, F_OK) == 0)
		{
			if (access(cmd_with_its_path, X_OK) == 0)
			{
				execve(cmd_with_its_path, av, env);
				exit((print_error("%s: %s\n", cmd, strerror(errno)), errno));
			}
			else
				exit((print_error("%s: Permition denied\n", cmd), 126));
		}
		i++;
	}
	exit((print_error("%s: command not found\n", cmd), 127));
}
