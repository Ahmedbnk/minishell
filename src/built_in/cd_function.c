#include "minishell.h"

int cd(char **env, char **path)
{
  char *old_dir;
  char *new_dir;
  int status = 0;

  if(are_they_equal(*path, "cd"))
    path++;
  old_dir = pwd(&status);
  if(chdir(*path) == 0)
  {
    new_dir = pwd(&status);
    update_env_dir(env, old_dir, new_dir);
  }
  else
  {
    print_error("%s\n" , strerror(errno));
    return 1;
  }
  return 0;
}
