#include "minishell.h"

void	fill_n_str(char *str, int n)
{
	int	len;

	len = n_counter(n);
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
}
