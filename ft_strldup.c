#include "minishell.h"

char	*ft_strldup(const char *str, int len)
{
	char	*string_clone;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	string_clone = malloc((len + 1) * sizeof(char));
	if (!string_clone)
		return (NULL);
	while (i < len)
	{
		string_clone[i] = str[i];
		i++;
	}
	string_clone[i] = '\0';
	return (string_clone);
}
