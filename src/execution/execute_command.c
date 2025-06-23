#include "minishell.h"

void  check_after_geting_bath( char *cmd, char **av, char **path, char **env)
{
	int i;
	char *cmd_with_slash;
	char *cmd_with_its_path;

	if(!path)
		return;
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
				exit((print_error("%s: %s\n", cmd, strerror(errno)), errno));
			}
			else
				exit((print_error("%s: Permition denied\n", cmd), 126));
		}
		i++;
	}
	exit((print_error("%s: command not found\n", cmd), 127));
}


void  check_the_access(char *cmd, char **av, char **env)
{
	if (access(cmd, F_OK) == 0)
	{
		if(access(cmd, X_OK) == 0)
		{
			execve(cmd , av, env);
				exit((print_error("%s: %s\n", cmd, strerror(errno)), errno));
		}
		else
				exit((print_error("%s: Permition denied\n", cmd), 126));
	}
	else
	  exit((print_error("%s: command not found\n", cmd), 127));
}


char **get_path()
{
	char	*path;
	char	**splited;

	path = getenv("PATH");
	splited = ft_split(path , ':');
	return splited;
}

void execute_command(t_shell_control_block *shell)
{
	if(!*shell->cmd_and_args)
		return;
	char **path = get_path();
	if(**shell->cmd_and_args == '/')
		check_the_access(*shell->cmd_and_args, shell->cmd_and_args, shell->env_cpy);
	else
		check_after_geting_bath(*shell->cmd_and_args ,shell->cmd_and_args , path , shell->env_cpy);
}

int how_many_strcut_in_the_array(t_token *arr_of_stracts)
{
	int number_of_structs;

	number_of_structs = 0;
	while(arr_of_stracts!= NULL )
	{
		number_of_structs++;
		arr_of_stracts = arr_of_stracts-> next;
	}
	return  number_of_structs;
}

char **get_cmd_and_its_args(t_shell_control_block *shell)
{
    int i;
    shell->cmd_and_args = ft_malloc( (how_many_strcut_in_the_array(shell->tokenze)+1)* sizeof(t_token ),1);
    i = 0;
	t_token *ptr;
	ptr = shell->tokenze;
	while (ptr) {
		if (ptr->word[0] == '\0')
			ptr = ptr->next;
		else {
			if (ptr->type == REDIR_IN ||
				ptr->type == HEREDOC ||
				ptr->type == REDIR_OUT ||
				ptr->type == REDIR_APPEND)
				ptr = ptr->next;
			else if (ptr->type == WORD)
				shell->cmd_and_args[i++] = ft_strdup(ptr->word, 1);
			else
				break;
			ptr = ptr->next;
		}
	}
	shell->cmd_and_args[i] = NULL;
  return shell->cmd_and_args;
}
