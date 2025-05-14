#ifndef MINISHELL_H
# define MINISHELL_H

# include "./Libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define single_q 39
# define double_q 34

typedef struct s_expand
{
	char			*befor_dollar;
	char			*to_expand;
	char			*after_expand;
	int				last_one;
}					t_expand;

typedef enum e_token_type
{
	WORD,         //  0 for regular words
	PIPE,         // | 1
	REDIR_IN,     // < 2
	REDIR_OUT,    // > 3
	REDIR_APPEND, // >> 4
	HEREDOC,      // << 5
}					token_t;

typedef struct s_token
{
	int				type;
	char			*word;
}					t_data;

//t_token				*add_node(t_token **list, t_token *node);
//t_token				*creat_node(char *str);

int					check_error(char *str);

void				sigint_handler(int signo);
void				handle_signals(void);
int					is_between_quotes(char *line, int index);
int					is_space(char c);
int					are_they_equal(const char *str1, const char *str2);

char	**customized_split(char const *s);
char        *expand_if_possible(char *string);
int					should_i_expand(char *str, int index);
int					is_expand_separator(char c);
char				**split_for_expantion(char const *s);
char				*custom_join(char const *s1, char const *s2);


void	allocat_and_init(t_expand **expand_list, int how_much_to_expand);
char				*new_str_after_expand(t_expand *data, int num_of_expantion);
void remove_quotes_from_args(char **splitted);
char	**split_with_operators(char **splitted);
void print_splitted(char **splitted);
int two_d_lenth(char **str);
t_data *make_token(char **arr);
#endif
