#include "minishell.h"

void	handle_expansion_result(t_shell_control_block *sh, t_name_lst *ptr,
		char *str)
{
	(void)sh;
	if (are_they_equal(ptr->file_name, str))
		return ;
	if (is_there_a_space_outside_q(str))
		ptr->status = AMBIGUOUS;
	ptr->file_name = str;
}
