#include "minishell.h"

void	handle_all_redir(t_shell_control_block *shell)
{
	while (shell->tokenze && shell->tokenze->word != NULL
		&& shell->tokenze->type != PIPE)
	{
		if (is_redirection(shell->tokenze->word))
		{
			if (shell->tokenze->type == HEREDOC)
				shell->in_file_name = shell->tokenze->heredoc_file_name;
			else if (shell->tokenze->type == REDIR_IN)
				handle_redir_in((shell->tokenze->next)->word, &(shell->in_file_name), shell);
			else if (shell->tokenze->type == REDIR_OUT)
				handle_redir_out((shell->tokenze->next)->word, &(shell->file_name), shell);
			else if (shell->tokenze->type == REDIR_APPEND)
				handle_append((shell->tokenze->next)->word, &(shell->file_name), shell);
		}
		shell->tokenze = shell->tokenze->next;
	}
}
