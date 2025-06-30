#include "minishell.h"

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
