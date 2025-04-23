#include "minishell.h"

int should_i_expand(char *str, int index)
{
  char quote = 0;
  quote = is_between_quotes(str, index);
  if(quote == single_q)
    return 0;
  else
    return 1;
}
