#ifndef MINISHELL_H
# define MINISHELL_H

/*******************************************************************************
 *                             INCLUDES                                        *
 *******************************************************************************/
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>

/*******************************************************************************
 *                           CONSTANTS AND MACROS                              *
 *******************************************************************************/
# define parent 1
# define child 2
# define single_q 39
# define double_q 34
# define BUFFER_SIZE 40
# define PROTECT 14
# define VALID 0
# define AMBIGUOUS 1
# define NEW_START 2

/*******************************************************************************
 *                           GLOBAL VARIABLES                                  *
 *******************************************************************************/
/*******************************************************************************
 *                         TYPE DEFINITIONS                                   *
 *******************************************************************************/
typedef enum e_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
}					t_type;

typedef struct s_token
{
	int				type;
	char			*word;
	char			*heredoc_file_name;
	char			*delimiter;
	struct s_token	*next;
}					t_token;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_expand
{
	char			*befor_dollar;
	char			*to_expand;
	char			*after_dollar;
	int				last_one;
	int				heredoc_flag;
}					t_expand;

typedef struct s_name_lst
{
	char			*file_name;
	int				status;
	struct s_name_lst	*next;
}					t_name_lst;

typedef struct s_shell_control_block
{
	char			**env_cpy;
	char			**env_of_export;
	char			*line;
	char			**splitted;
	char			*porotect_var;
	t_name_lst		*file_name_lst;
	t_token			*tokenze;
	char			**cmd_and_args;
	t_expand		*expand_arr;
	int				arr[2];
	int				previous_read_end;
	t_token			*line_pointer;
	char			*in_file_name;
	char			*file_name;
	int				fd_out;
	int				fd_in;
	int				last_child_pid;
	int				wait_status;
	int				exit_status;
	int             exit_status_flag;
	int				original_stdin;
	int				original_stdout;
}					t_shell_control_block;

/*******************************************************************************
 *                     CHECKER FUNCTION PROTOTYPES                            *
 *******************************************************************************/
int		is_space(char c);
int		is_quote(char c);
int		is_dollar(char c);
int		is_all_spaces(const char *str);
int		is_it_key_value(char *str);
int		is_valid_var(char *str);
int		is_redirection(char *str);
int		is_pipe(char *str);
int		is_there_a_char(char *str);
int		is_there_a_pipe(t_shell_control_block *shell);
int		is_protected(t_shell_control_block *sh, char *str, int index);
int		is_between_quotes(char *line, int index);
int		is_there_invalid_expantion(t_shell_control_block *sh, char *str, char *old_str);
int		is_expand_separator(char c);
int		is_expend_seperator(char c);
int		should_i_expand(char *str, int index);
int		are_they_equal(const char *str1, const char *str2);
int		compare_env_var(char *var1, char *var2);
int		is_it_valid_dollar(char *str);
int		is_out_dollar(char *str, int index);
int		is_symbole(int type);
int		is_builtin(char *str);
int		is_valid_flag(char *str);
int		is_the_var_in_env(char **env, char *var);
int		is_red_symbole(char *str);
int		is_operator(char *str, int i);

/*******************************************************************************
 *                    LIBFT FUNCTION PROTOTYPES                               *
 *******************************************************************************/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *big, const char *little, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s, int flag);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_lstsize(t_list *list);
void	*ft_malloc(size_t size, int falg);
void	ft_putstr_fd(char *s, int fd);
void	ft_strcpy(char *dst, const char *src);

/*******************************************************************************
 *                     LIST HANDLING PROTOTYPES                               *
 *******************************************************************************/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	**get_garbage_pointer(int flag);
t_list	*garbage_collection_lstnew(void *content, int flag);
void	free_memory(t_list **lst);

t_name_lst	*new_file_name(void *name_of_file, int status);
void		add_back_file_name(t_name_lst **lst, t_name_lst *new);
t_token		*new_token(void *content, int type);
void		add_token_to_lst(t_token **lst, t_token *new);
t_type		get_token_type(const char *str);

/*******************************************************************************
 *                     BUILT-IN COMMAND PROTOTYPES                           *
 *******************************************************************************/
int		cd(char **env, char **path);
int		echo(char **args);
int		unset(char ***env, char **vars);
int		export(t_shell_control_block *s, char **to_export);
char	*pwd(int *status);
int		print_env(char **env);

/*******************************************************************************
 *                     STRING HANDLING PROTOTYPES                             *
 *******************************************************************************/
char	*get_next_line(int fd);
char	*generate_random_name(void);
char	*read_file(char *file_name);
char	*expand_if_possible(t_shell_control_block *s, char *str, int heredoc_flag);
char	*custom_join(char const *s1, char const *s2);
char	*new_str_after_expand(t_shell_control_block *s, int num_of_expantion);
char	*get_env_var(t_shell_control_block *shell, t_expand data);
char	*buffering(char *s1, char *s2, char *s3);
char	*add_new_line(char *str);
char	*expnad_and_join_node(t_shell_control_block *s, t_expand data);
char	*protect_str(t_shell_control_block *sh, char *str);
char	*remove_dollar_if_quotes_after_it(char *str);

/*******************************************************************************
 *                     OUTPUT HANDLING PROTOTYPES                             *
 *******************************************************************************/
void	print(int fd, char *str);
void	print_file(char *str);
void	print_exit_signal_message(int exit_status);
void	print_splitted(char **splitted);
void	s(char *str);

/*******************************************************************************
 *                     SIGNAL HANDLING PROTOTYPES                             *
 *******************************************************************************/
void	handle_signals(void);
void	handler(int signo);
void	first_range(int exit_status);
void	second_range(int exit_status);
void	third_range(int exit_status);

/*******************************************************************************
 *                     STRING AND QUOTE PROCESSING                            *
 *******************************************************************************/
void	rm_quotes_from_one_str(t_shell_control_block *sh, char **line);
void	rm_quotes_from_one_str_helper(t_shell_control_block *sh, char *line, char **parsed_quote_line);

/*******************************************************************************
 *                     ARRAY MANIPULATION PROTOTYPES                          *
 *******************************************************************************/
char	**customized_split(char const *s);
char	**copy_env(char **env);
char	**handle_dollar_with_quotes(char **splitted);
char	**split_with_operators(char **splitted);
char	**get_cmd_and_its_args(t_shell_control_block *shell);
char	**get_path(void);
char	**add_var_to_env(char **env, char *var);

/*******************************************************************************
 *                     ENVIRONMENT HANDLING PROTOTYPES                        *
 *******************************************************************************/
void	allocat_and_init(t_expand **expand_list, int how_much_to_expand, int heredoc_flag);
void	allocat_arr_of_structs_list(t_expand **expand_list, int how_much_to_expand);
void	init_arr_of_structs_list(t_expand *expand_list, int how_much_to_expand, int heredoc_flag);
void	remove_var_from_env(char ***env, char *var);
void	get_files_name(t_shell_control_block *s);
void	get_start_and_end(char *str, int *start, int *end);
int		count_number_of_qute(char *str);

/*******************************************************************************
 *                     EXPANSION AND PARSING PROTOTYPES                       *
 *******************************************************************************/
void	split_after_expantion(t_shell_control_block *sh, char *str, char *old_str);
void	expand_and_split_helper(t_shell_control_block *sh, int index);
void	expand_and_split(t_shell_control_block *sh);
void	string_after_dollar(t_expand *data, char *str, int *offset);
void	string_before_dollar(t_expand *data, char *str, int *offset);
void	string_to_expand(t_expand *data, char *str, int *offset);
int		how_many_dallar_to_expand(char *str, int heredoc_flag);

/*******************************************************************************
 *                     REDIRECTION HANDLING PROTOTYPES                        *
 *******************************************************************************/
void	handle_redir_in(char *str, char **in_file_name);
void	handle_redir_out(char *str, char **file_name);
void	handle_append(char *str, char **file_name);
void	create_all_heredocs(t_shell_control_block *shell);
void	create_heredoc(t_shell_control_block *s, t_token *tokenze);
void	process_redirection_tokens(t_shell_control_block *shell);
int		parse_redirections(t_shell_control_block *shell);
void	init_redirection_vars(t_shell_control_block *shell);
void	setup_input_redirection(t_shell_control_block *shell);
void	setup_output_redirection(t_shell_control_block *shell);
void	save_original_fds(t_shell_control_block *shell);
void	restore_original_fds(t_shell_control_block *shell);
int		check_ambiguous_redirection(t_shell_control_block *shell);

/*******************************************************************************
 *                     ERROR CHECKING PROTOTYPES                              *
 *******************************************************************************/
int		check_error(t_shell_control_block *shell);
int		check_syntax_error(char **splitted);
int		check_unclosed_quotes(char *str);
int		validate_pipe_syntax(char **splitted, int i);
int		validate_redirection_syntax(char **splitted, int i);
int		len_of_two_d_array(char **str);
int		parse_line(t_shell_control_block *sh);
int		n_counter(int n);
void	fill_n_str(char *str, int n);

/*******************************************************************************
 *                     EXECUTION PROTOTYPES                                  *
 *******************************************************************************/
void	execute_command_line(t_shell_control_block *shell);
void	execute_command_line_helper(t_shell_control_block *shell);
void	execute_line(t_shell_control_block *sh);
void	execute_command(t_shell_control_block *shell);
void	execute_builtin(t_shell_control_block *shell);
void	execute_parent_builtin(t_shell_control_block *shell);
void	execute_builtin_child(t_shell_control_block *shell);
void	process_command(t_shell_control_block *shell);
void	check_after_geting_path(char *cmd, char **av, char **path, char **env);
void	check_the_access(char *cmd, char **av, char **env);
int		cmd_size(t_token *tokenz);
void	process_pipe_token(t_shell_control_block *sh);
void	process_redirection_token(t_shell_control_block *sh, char **ptr);
void	handle_all_redir(t_shell_control_block *shell);
void	parse_tokens(t_shell_control_block *sh);
void	prepare_lst(t_shell_control_block *sh);
void	handle_expansion_result(t_shell_control_block *sh, t_name_lst *ptr, char *str);
void	skip_ambig_list(t_shell_control_block *shell);
void	skip_command(t_token **tokenized_address);
void	split_helper(char **splitted, char *s, int i, int k);
void	split_string_with_operators(char **container, char *str, int *j_ptr);
int		ft_w_counter(char const *s, char c);
int		calculate_all_symboles_operators(char **splitted);
int		does_it_has_qoutes(char *str);
int		does_string_has_operators(char *str);
int		is_there_a_space_outside_q(char *str);
void	advance_file_name_list(t_shell_control_block *shell);
int		find_and_update_var(char **env, char *var);
void	update_env_dir(char **env, char *old_dir, char *new_dir);
void	sort_env(char **env);

/*******************************************************************************
 *                     SHELL INITIALIZATION AND CONTROL                       *
 *******************************************************************************/
t_shell_control_block	*get_shell_pointer(t_shell_control_block *ptr);
char	*ft_readline(t_shell_control_block *sh);
void	ft_init_shell_block(t_shell_control_block *sh, int ac, char **av);
int		ft_w_counter_split(char const *s, char c);

char	*ft_getenv(void);
void	ft_close(int fd);
long long ft_atol(const char *str);
int	check_is_valid_number(const char *str);
int my_exit(char **args);
int set_handler_state(int state);
void	make_fd_lst(void);
int	**get_fd_pointer(void);
#endif
