#include "minishell.h"

void	execute_line(t_shell_control_block *sh)
{
	if (sh->tokenze)
	{
		create_all_heredocs(sh);
		get_cmd_and_its_args(sh);
		if (!is_there_a_pipe(sh) && is_builtin(*sh->cmd_and_args))
      execute_parent_builtin(sh);
		else
			execute_command_line(sh);
	}
}
