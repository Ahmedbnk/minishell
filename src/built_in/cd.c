#include "minishell.h"

void update_env_dir(char **env, char *old_dir, char *new_dir)
{
    int i;
    i = 0;
    while(env[i])
    {
        if(ft_strncmp(env[i], "OLDPWD=", 7) == 0)
            env[i] = ft_strdup(ft_strjoin("OLDPWD=", old_dir), 0);
        else if(ft_strncmp(env[i], "PWD=", 4) == 0)
            env[i] = ft_strdup(ft_strjoin("PWD=", new_dir), 0);
        i++;
    }
}

int cd(char **env, char **path)
{
  char *old_dir;
  char *new_dir;
  int status;
  int len;

  status = 0;

  len = len_of_two_d_array(path);
  if(len > 2)
    return(print_error("too many arguments\n"), 1);
  if(are_they_equal(*path, "cd"))
    path++;
  old_dir = pwd(&status);
  if(chdir(*path) == 0)
  {
    new_dir = pwd(&status);
    update_env_dir(env, old_dir, new_dir);
  }
  else
    return(print_error("%s\n" , strerror(errno)), 1);
  return 0;
}
