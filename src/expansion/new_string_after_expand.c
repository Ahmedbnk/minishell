#include "minishell.h"

char	*new_str_after_expand(t_shell_control_block *s, int num_of_expantion)
{
	char	*new_after_expand;
	char	*expanded;
	char	*joined;
	int		i;

	new_after_expand = NULL;
	i = 0;
	while (i < num_of_expantion)
	{
		if (num_of_expantion - i == 1)
			s->expand_arr[i].last_one = 1;
		expanded = expnad_and_join_node(s, s->expand_arr[i]);
		if (!expanded)
			return (NULL);
		joined = custom_join(new_after_expand, expanded);
		new_after_expand = joined;
		if (!new_after_expand)
			return (NULL);
		i++;
	}
	return (new_after_expand);
}
