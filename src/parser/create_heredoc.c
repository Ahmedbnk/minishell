#include "minishell.h"

void create_heredoc(char *str)
{
  int fd;
  char *buffer;

  buffer = NULL;
  
  fd = open("tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
  while(1)
  {
    buffer = readline("> ");
    if(buffer == NULL)
    {
      printf("bash: warning: here-document at line 1 delimited by end-of-file (wanted `%s') ",str);
      return;
    }
    if(are_they_equal(str, buffer))
      break;
    write(fd,buffer,ft_strlen(buffer));
    write(fd,"\n", 1);
  }
  close(fd);
  //print_file("tmp");
   unlink("tmp");
}
