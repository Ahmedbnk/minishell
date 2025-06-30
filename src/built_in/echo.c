#include "minishell.h"

static int	is_valid_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] != '-' || str[i + 1] != 'n')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(char **args)
{
	int	new_line_flag;
	args++;

	new_line_flag = 0;
	if (is_valid_flag(*args))
	{
		new_line_flag = 1;
		args++;
	}
	while (*args)
	{
		printf("%s", *args);
		if (*(args + 1) != NULL)
			printf(" ");
		args++;
	}
	if (!new_line_flag)
		printf("\n");
  return 0;
}
