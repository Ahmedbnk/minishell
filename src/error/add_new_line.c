#include "minishell.h"

char	*add_new_line(char *str)
{
	char	*str_with_new_line;

	return (str_with_new_line = custom_join(str, "\n"));
}
