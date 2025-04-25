#include "minishell.h"

int is_valid_env_char(char c)
{
  if(ft_isalnum(c) || c == '_')
    return 1;
  return 0;
}
