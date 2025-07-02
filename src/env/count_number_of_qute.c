#include "minishell.h"

int count_number_of_qute(char *str)
{
  int number_of_qute;
  number_of_qute = 0;

  while(*str)
  {
    if(is_quote(*str))
      number_of_qute++;
    str++;
  }
  return number_of_qute;
}
