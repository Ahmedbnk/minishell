#include "minishell.h"

int	n_counter(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter = 1;
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}
