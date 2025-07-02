#include "minishell.h"

int	ft_w_counter_split(char const *s, char c)
{
	int	i;
	int	k;
	int	counter;

	i = 0;
	k = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			k = 0;
		}
		else
		{
			if (k == 0)
				counter++;
			k = 1;
		}
		i++;
	}
	return (counter);
}
