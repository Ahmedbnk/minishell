#include "minishell.h"

int parse_redirections(t_shell_control_block *shell)
{
  t_token *original_tokenized;

  original_tokenized = shell->tokenze;
  while (shell->tokenze && shell->tokenze->word != NULL && shell->tokenze->type != PIPE)
  {
    if (is_redirection(shell->tokenze->word))
    {
      if (check_ambiguous_redirection(shell))
      {
        shell->tokenze = original_tokenized;
        return 1;
      }
      advance_file_name_list(shell);
    }
    process_redirection_tokens(shell);
    shell->tokenze = shell->tokenze->next;
  }
  shell->tokenze = original_tokenized;
  return 0;
}
