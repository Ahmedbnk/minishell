#include "minishell.h"

char	**get_cmd_and_its_args(t_shell_control_block *sh)
{
	int		i;
	t_token	*ptr;

	sh->cmd_and_args = ft_malloc((cmd_size(sh->tokenze) + 1) * sizeof(t_token),
			1);
	i = 0;
	ptr = sh->tokenze;
	while (ptr)
	{
		if (is_symbole(ptr->type))
			ptr = ptr->next;
		else if (ptr->type == WORD)
			sh->cmd_and_args[i++] = ft_strdup(ptr->word, 1);
		else
			break ;
		ptr = ptr->next;
	}
	sh->cmd_and_args[i] = NULL;
	return (sh->cmd_and_args);
}
