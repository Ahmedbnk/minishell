#include "minishell"

int check_after_geting_bath( char *cmd, char **path)
{
  int i;
  char *cmd_with_slash;

  cmd_with_slash = ft_strjoin("/", cmd);
  while(path[i])
  {
    if(access((ft_strjoin(path[i] ,cmd_with_slash)), F_OK) = 0)
    {
      if(access((ft_strjoin(path[i] ,cmd_with_slash)), X_OK) = 0)
        return 1;
      else
        exit((printf("%s: %s\n", cmd, strerror(errno)), 1));
    }
    i++;
  }
  exit((printf("%s: %s\n", cmd, strerror(errno)), 1));
  return 0;
}


int  check_the_access(char *cmd)
{
  if (access(cmd, F_OK) == 0)
  {
    if(access(cmd, X_OK) == 0)
      return 1;
    else
      exit((printf("%s: %s\n", cmd, strerror(errno)), 1));
  }
  else
      exit((printf("%s: %s\n", cmd, strerror(errno)), 1));
  return ;
}

int  check_command_status(char *cmd, char **env)
{
  if(!cmd)
    return; 
  if(*cmd == '/')
    if(check_the_access(*cmd))
      return 1;
  else
      if(check_after_geting_bath(cmd , env))
      return 1;
  return 0;
}

void execute_command(char *cmd , char **av, char **env)
{
  if(check_command_status(cmd, env))
  {
    execve(cmd , av, env);
    exit((printf("%s: %s\n", cmd, strerror(errno)), 1));
  }
}

// void get_the_command_data(char **main_env)
// {
// 	char	**env_copy;
// 	char	**cmd_and_args;
//
// 	env_copy = copy_env(main_env);
// 	cmd_and_args = get_cmd_and_its_args();
// 	execute_command( , , env_copy);
//
// }


char **get_cmd_and_its_args(t_data *arr_of_stracts)
{
	int i;
	int j;
	char **cmd_and_args;

	i = 0;
	j = 0;
	while(arr_of_stracts[i].word != NULL)
	{
		if(arr_of_stracts[i].type == REDIR_IN || arr_of_stracts[i].type == HEREDOC)
			i++;
		else if(arr_of_stracts[i].type == WORD)
			cmd_and_args[j++] = ft_strdup(arr_of_stracts[i]);
		else
			break;
		i++;
	}
	return cmd_and_args;
}

int main(int ac, char **av, char **env)
{
  (void) ac;
  char *cmd = "/bin/ls";
}


