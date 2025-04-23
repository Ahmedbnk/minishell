#include "minishell.h"

int is_between_quotes(char *line, int index)
{
 return (is_between_double_quotes(line, index)
  || is_between_single_quotes(line, index));
}
