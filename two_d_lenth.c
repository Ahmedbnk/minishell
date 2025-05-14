
#include "minishell.h"

int two_d_lenth(char **str)
{
  int counter;
  counter = 0;
  while(str[counter])
  {
    counter++;
  }
  return counter;
}
