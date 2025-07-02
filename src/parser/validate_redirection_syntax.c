#include "minishell.h"

int	validate_redirection_syntax(char **splitted, int i)
{
	if (!splitted[i + 1])
		return (print(2, "syntax error near unexpected str `newline'\n"), 1);
	if (is_pipe(splitted[i + 1]) || is_red_symbole(splitted[i + 1]))
		return (print(2, "syntax error near unexpected str `newline'\n"), 1);
	return (0);
}
