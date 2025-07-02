#include "minishell.h"


char	**ft_split(char const *s, char c)
{
	char	**splitted;

	int(i), (k), (start);
	if (!s)
		return (NULL);
	splitted = ft_malloc((ft_w_counter(s, c) + 1) * sizeof(char *), 1);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			splitted[k++] = ft_substr(s, start, i - start);
	}
	splitted[k] = NULL;
	return (splitted);
}
