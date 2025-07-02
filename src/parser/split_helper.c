#include "minishell.h"

void	split_helper(char **splitted, char *s, int i, int k)
{
	int	start;

	start = 0;
	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		start = i;
		while (s[i] && (!is_space(s[i]) || (is_space(s[i])
					&& is_between_quotes(s, i))))
			i++;
		if (i > start)
			splitted[k++] = ft_substr(s, start, i - start);
	}
	splitted[k] = NULL;
}
