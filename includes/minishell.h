/* Function prototypes for execution functions */
void	check_after_geting_path(char *cmd, char **av, char **path, char **env);
void	check_the_access(char *cmd, char **av, char **env);
char	**get_path(void);
void	execute_command(t_shell_control_block *shell);
int	cmd_size(t_token *tokenz);
int	is_symbole(int type);
char	**get_cmd_and_its_args(t_shell_control_block *sh);
void	print_exit_signal_message(int exit_status);

/* Function prototypes for signal message functions */
void first_range(int exit_status);
void second_range(int exit_status);
void third_range(int exit_status);
