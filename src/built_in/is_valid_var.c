#include "minishell.h"

int	is_valid_var(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return ((print(2, buffering("export: `", str,
						"' : not a valid identifier\n")), 1));
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && str[i] != '_' && !ft_isdigit(str[i]))
			return ((print(2, buffering("export: `", str,
							"' : not a valid identifier\n")), 1));
		i++;
	}
	return (1);
}
