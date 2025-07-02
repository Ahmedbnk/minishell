#include "minishell.h"

int	calculate_all_symboles_operators(char **splitted)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	j = 0;
	number = 0;
	while (splitted[i])
	{
		j = 0;
		while (splitted[i][j])
		{
			if (!is_between_quotes(splitted[i], j) && strchr("<>|",
					splitted[i][j]))
				number++;
			j++;
		}
		i++;
	}
	return (number);
}
