#include "minishell.h"

void advance_file_name_list(t_shell_control_block *shell)
{
  if (shell->file_name_lst)
    shell->file_name_lst = shell->file_name_lst->next;
}
