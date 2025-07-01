#include "minishell.h"

int	is_symbole(int type)
{
	return (type == REDIR_IN || type == HEREDOC || type == REDIR_OUT
		|| type == REDIR_APPEND);
}
