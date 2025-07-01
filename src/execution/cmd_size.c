#include "minishell.h"

int	cmd_size(t_token *tokenz)
{
	int	size;

	size = 0;
	while (tokenz)
	{
		if (is_redirection(tokenz->word) || tokenz->type == HEREDOC)
    {
			tokenz = tokenz->next;
    }
		else if (tokenz->type == WORD)
			size++;
		tokenz = tokenz->next;
	}
	return (size);
}
