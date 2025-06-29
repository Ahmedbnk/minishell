#include "minishell.h"

t_shell_control_block	*get_shell_pointer(t_shell_control_block *ptr)
{
	static t_shell_control_block * pointer_to_ptr;
	if(ptr)
		pointer_to_ptr = ptr;
	return pointer_to_ptr;
}
