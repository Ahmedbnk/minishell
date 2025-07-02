#include "minishell.h"

int	parse_redirections(t_shell_control_block *shell)
{
	t_token	*original_tokenized;

	original_tokenized = shell->tokenze;
	while (shell->tokenze && shell->tokenze->word != NULL
		&& shell->tokenze->type != PIPE)
	{
		if (is_symbole(shell->tokenze->type))
		{
			process_redirection_tokens(shell);
			if (check_ambiguous_redirection(shell))
				return (1);
			shell->tokenze = shell->tokenze->next;
		}
		shell->tokenze = shell->tokenze->next;
	}
	shell->tokenze = original_tokenized;
	return (0);
}
