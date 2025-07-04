#include "minishell.h"

void	free_all(void)
{
	free_fd_lst();
	free_memory(get_garbage_pointer(1));
	free_memory(get_garbage_pointer(0));
}
int	main(int ac, char **av, char **env)
{
	t_shell_control_block	sh;

	ft_init_shell_block(&sh, ac, av);
	sh.env_of_export = copy_env(env);
	sh.env_cpy = copy_env(env);
	get_shell_pointer(&sh);
	handle_signals();
	while (1)
	{
		make_fd_lst();
		set_handler_state(0);
		if (!ft_readline(&sh) || parse_line(&sh))
			continue ;
		execute_line(&sh);
		free_fd_lst();
		free_memory(get_garbage_pointer(1));
		free(sh.line);
	}
	return (0);
}
