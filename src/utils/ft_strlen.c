#include "minishell.h"

size_t	ft_strlen(const char *s)
{
  if(!s)
    return (0);
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
