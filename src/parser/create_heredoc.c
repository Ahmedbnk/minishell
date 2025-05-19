#include "minishell.h"

void create_heredoc(char *str)
{
  int fd;
  char *buffer;
  char *buffer2;
  char *buffer3;

  
  fd = open("tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
  buffer3 = NULL;
  while(1)
  {
    buffer = readline("> ");
    if(are_they_equal(str, buffer))
      break;
    write(fd,buffer,ft_strlen(buffer));
    write(fd,"\n", 1);
  }
  close(fd);
  fd = open("tmp", O_CREAT | O_RDWR , 0777);
  buffer2 = get_next_line(fd);
  while(buffer2)
  {
    buffer3 = ft_strjoin(buffer3, buffer2);
    buffer2 = get_next_line(fd);
  }
  // printf("the buffer content is %s\n", buffer3);
   // unlink("tmp");
  close(fd);
}
