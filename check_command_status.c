#include "minishell"
void go_run_command(void);
void  check_command(char *cmd);
void  check_command_status(char *cmd);
void check_after_geting_bath(char *cmd, );



int main(int ac, char **av, char **env)
{
  (void) ac;
  char *cmd = "/bin/ls";
}

void check_after_geting_bath(char *cmd, char **path)
{
  int i;
  char *cmd_with_slash;
  cmd_with_slash = ft_strjoin("/", cmd);
  while(path[i])
  {
    check_command(ft_strjoin(path[i] ,cmd_with_slash));
    i++;
  }
}


void  check_command_status(char *cmd)
{
  if(!cmd)
    return; 
  if(*cmd == '/')
    check_command(*cmd);
  else
    check_after_geting_bath();
}

void  check_command(char *cmd)
{
  if (access(cmd, F_OK) == 0) 
  {
    if(access(cmd, X_OK) == 0)
      go_run_command(void);
    else
    {
      printf("%s: %s\n", cmd, strerror(errno));
    }
  }
  else
  {
    printf("%s: %s\n", cmd, strerror(errno));
  }
}

void go_run_command(void){}
