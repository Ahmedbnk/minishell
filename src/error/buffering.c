#include "minishell.h"

char	*buffering(char *s1, char *s2, char *s3)
{
	char	*first_join;
	char	*second_join;

	first_join = custom_join(s1, s2);
	second_join = custom_join(first_join, s3);
	return (second_join);
}
