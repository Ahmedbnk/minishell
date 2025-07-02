#include "minishell.h"

int	check_ambiguous_redirection(t_shell_control_block *shell)
{
	if (shell->file_name_lst && shell->file_name_lst->status == AMBIGUOUS)
	{
		print(2, "ambig\n");
		shell->exit_status = 1;
		return (1);
	}
	return (0);
}
