#include "minishell.h"
void print_file(char *str)
{
  char *buffer;

  buffer = read_file(str);
  printf("%s", buffer);
}
