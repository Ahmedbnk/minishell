#include "minishell.h"

void handle_redir_in(char *str, char **in_file_name, t_shell_control_block *shell)
{
  char *buffer;
  int fd;
  shell = get_shell_pointer(NULL);
  buffer = NULL;

  *in_file_name = str; 
  fd = open(*in_file_name, O_RDWR | O_TRUNC, 0766);
  if(fd < 0)
  {
    perror(*in_file_name);
    shell->exit_status = 1;
    return;
  }
  buffer = read_file(str);
  if(!buffer)
    return;
  write(fd,buffer, ft_strlen(buffer));
  ft_close(fd);
}
