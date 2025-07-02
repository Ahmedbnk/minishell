#include "minishell.h"

char	**customized_split(char const *s)
{
	char	**splitted;
	int		i;
	int		k;
  //lmouchkil kan hna
  if(*s == '\0' || is_all_spaces(s))
  {
    splitted = ft_malloc(2 *sizeof(char *),1);
    splitted[0] = ft_strdup("", 1);
    splitted[1] = NULL;
    return splitted;
  }

	if (!s)
		return (NULL);
	splitted = ft_malloc((ft_w_counter(s) + 1) * sizeof(char *), 1);
	i = 0;
	k = 0;
	split_helper(splitted, (char *)s, i, k);
	return (splitted);
}
