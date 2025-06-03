#include "minishell.h"

void  check_after_geting_bath( char *cmd, char **av, char **path, char **env)
{
	int i;
	char *cmd_with_slash;
	char *cmd_with_its_path;

	i = 0;
	cmd_with_slash = ft_strjoin("/", cmd);
	while(path[i])
	{
		cmd_with_its_path = ft_strjoin(path[i] ,cmd_with_slash);
		if(access(cmd_with_its_path, F_OK) == 0)
		{
			if(access(cmd_with_its_path, X_OK) == 0)
			{
				execve(cmd_with_its_path , av, env);
				exit((print_error("%s: %s\n", cmd, strerror(errno)), 1));
			}
			else
				exit((print_error("%s: %s\n", cmd, strerror(errno)), 1));
		}
		i++;
	}
	exit((print_error("%s: %s\n", cmd, strerror(errno)), 1));
}


void  check_the_access(char *cmd, char **av, char **env)
{
	if (access(cmd, F_OK) == 0)
	{
		if(access(cmd, X_OK) == 0)
		{
			execve(cmd , av, env);
			exit((print_error("%s: %s\n", cmd, strerror(errno)), 1));
		}
		else
			exit((print_error("%s: %s\n", cmd, strerror(errno)), 1));
	}
	else
		exit((print_error("%s: %s\n", cmd, strerror(errno)), 1));
}


char **get_path()
{
	char	*path;
	char	**splited;

	path = getenv("PATH");
	splited = ft_split(path , ':');
	return splited;
}

void execute_command(char *cmd , char **av, char **env)
{
	if(!cmd)
		return;
	char **path = get_path();
	if(*cmd == '/')
		check_the_access(cmd, av, env);
	else
		check_after_geting_bath(cmd ,av , path , env);
}

int how_many_strcut_in_the_array(t_data *arr_of_stracts)
{
	int number_of_structs;

	number_of_structs = 0;
	while(arr_of_stracts->word != NULL )
	{

		number_of_structs++;
		arr_of_stracts++;
	}
	return  number_of_structs;
}

//char **get_cmd_and_its_args(t_data *arr_of_stracts)
char **get_cmd_and_its_args(t_shell_control_block *shell)
{
	int i;
	int j;

	shell->cmd_and_args = ft_malloc( how_many_strcut_in_the_array(shell->tokenized)* sizeof(t_data ));

	i = 0;
	j = 0;
	while(shell->tokenized[i].word != NULL)
	{
		if(shell->tokenized[i].type == REDIR_IN || shell->tokenized[i].type == HEREDOC || 
		shell->tokenized[i].type == REDIR_OUT || shell->tokenized[i].type == REDIR_APPEND)
			i++;
		else if(shell->tokenized[i].type == WORD)
		{

			cmd_and_args[j] = ft_strdup(shell->tokenized[i].word);
		j++;
	}
		else
			break;
		i++;
	}
	cmd_and_args[j] = NULL;
	return cmd_and_args;
}
