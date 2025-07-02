#include "minishell.h"

int	is_there_a_space_outside_q(char *str)
{
	int	i;
	int	status;

	if (!str)
		return (0);
	i = 0;
	status = 0;
	if (!is_there_a_char(str))
		return (1);
	while (str[i])
	{
		if (!is_space(str[i]) && (status == 0 || status == 2))
			status++;
		else if (is_space(str[i]) && status == 1)
			status++;
		if (status == 3)
			return (1);
		i++;
	}
	return (0);
}
