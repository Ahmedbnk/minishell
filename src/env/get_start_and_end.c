#include "minishell.h"

void get_start_and_end(char *str, int *start, int *end)
{
  int i;
  i = 0;
  while(str[i])
  {
    if(str[i] == '=')
      *start = i+1;
    i++;
  }
  *end = i;
}
