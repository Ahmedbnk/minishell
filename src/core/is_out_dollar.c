#include "minishell.h"

int is_out_dollar(char *str, int index)
{
	if(!str)
		return 0;
	return (is_dollar(str[index]) && !is_between_quotes(str, index));
}
