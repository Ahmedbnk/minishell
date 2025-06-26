int is_it_valid_dollar(char *str);
int is_there_invalid_expantion(t_shell_control_block *sh, char *str, char *old_str);
void split_after_expantion(t_shell_control_block *sh, char *str, char *old_str);
void expand_and_split_helper(t_shell_control_block *sh, int index);
void expand_and_split(t_shell_control_block *sh);
int parse_line(t_shell_control_block *sh);
void execute_line(t_shell_control_block *sh);
char *ft_readline(t_shell_control_block *sh);
void ft_init_shell_block(t_shell_control_block *sh, int ac, char **av);
