#include "minishell.h"

static int	ft_w_counter(char const *s)
{
	int	i;
	int	k;
	int	counter;

	i = 0;
	k = 0;
	counter = 0;
	while (s[i])
	{
		if (is_space(s[i]))
			k = 0;
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

static void	*ft_freesplit(char **a)
{
	int	i;

	i = 0;
	if (!a)
		return (NULL);
	while (a[i])
		free(a[i++]);
	free(a);
	return (NULL);
}

static void split_helper(char **splitted, char *s, int i, int k)
{
  int start;

  start = 0;
	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		start = i;
		while (s[i] && (!is_space(s[i])
          || (is_space(s[i]) && is_between_quotes(s, i))))
			i++;
		if (i > start)
			splitted[k++] = ft_substr(s, start, i - start);
		if (!splitted)
			ft_freesplit(splitted);
	}
	splitted[k] = NULL;
}
char	**customized_split(char const *s)
{
	char	**splitted;

	int i;
  int k;
	if (!s)
		return (NULL);
	splitted = malloc((ft_w_counter(s) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	k = 0;
  split_helper(splitted, (char *)s, i, k);
	return (splitted);
}
// #include <stdio.h>
// int	main(void)
// {
//   char *line = readline(">>> :");
//   char **splitted = customized_split(line);
//   for(int i = 0; splitted[i];i++)
//   {
//     printf("%s\n", splitted[i]);
//   }
//   return (0);
// }
