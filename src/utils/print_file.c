#include "minishell.h"

void print_file(char *str)
{
  char *buffer;
  int fd;


  fd = open(str, O_CREAT | O_RDWR , 0777);
  buffer = get_next_line(fd);
  while(buffer)
  {
    printf("%s", buffer);
    buffer = get_next_line(fd);
  }
  close(fd);
}
