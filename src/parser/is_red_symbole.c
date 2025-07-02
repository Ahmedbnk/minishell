#include "minishell.h"

int	is_red_symbole(char *str)
{
	if (!str)
		return (0);
	if (are_they_equal(str, "<")  || are_they_equal(str, ">") )
		return (1);
	if (are_they_equal(str, ">>")  || are_they_equal(str, "<<") )
		return (1);
	return (0);
}
