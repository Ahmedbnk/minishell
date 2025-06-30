#include "minishell.h"

void process_redirection_tokens(t_shell_control_block *shell)
{
  if (shell->tokenze->type == HEREDOC)
    shell->in_file_name = shell->tokenze->heredoc_file_name;
  else if (shell->tokenze->type == REDIR_IN)
    handle_redir_in((shell->tokenze->next)->word, &(shell->in_file_name));
  else if (shell->tokenze->type == REDIR_OUT)
    handle_redir_out((shell->tokenze->next)->word, &(shell->file_name));
  else if (shell->tokenze->type == REDIR_APPEND)
    handle_append((shell->tokenze->next)->word, &(shell->file_name));
}
