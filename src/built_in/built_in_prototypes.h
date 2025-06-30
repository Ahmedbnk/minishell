#ifndef BUILT_IN_PROTOTYPES_H
#define BUILT_IN_PROTOTYPES_H

void update_env_dir(char **env, char *old_dir, char *new_dir);
void execute_builtin(t_shell_control_block *shell);
void save_original_fds(t_shell_control_block *shell);
void restore_original_fds(t_shell_control_block *shell);
void init_redirection_vars(t_shell_control_block *shell);
int check_ambiguous_redirection(t_shell_control_block *shell);
void advance_file_name_list(t_shell_control_block *shell);
void process_redirection_tokens(t_shell_control_block *shell);
int parse_redirections(t_shell_control_block *shell);
void setup_output_redirection(t_shell_control_block *shell);
void setup_input_redirection(t_shell_control_block *shell);
void execute_parent_builtin(t_shell_control_block *shell);
int is_valid_flag(char *str);
int find_and_update_var(char **env, char *var);
char **add_var_to_env(char **env, char *var);
void sort_env(char **env);
int is_the_var_in_env(char **env, char *var);
void remove_var_from_env(char ***env, char *var);
int unset(char ***env, char **vars);
int is_it_key_value(char *str);
int is_valid_var(char *str);
int compare_env_var(char *var1, char *var2);
int export(t_shell_control_block *s, char **to_export);
int echo(char **args);
int print_env(char **env);
int cd(char **env, char **path);
char *pwd(int *status);
int is_builtin(char *str);

#endif
