#ifndef  MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include    "./Libft/libft.h" 

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

#define single_q 39
#define double_q 34

typedef enum e_token_type
{
    TOKEN_WORD,        // for regular words
    TOKEN_PIPE,        // |
    TOKEN_REDIR_IN,    // <
    TOKEN_REDIR_OUT,   // >
    TOKEN_REDIR_APPEND,// >>
    TOKEN_HEREDOC,     // <<
    TOKEN_EOF
    // add more as needed
}   token_t;

typedef struct s_token
{
    int type;
    char *word;
    struct s_token *next;
} t_token;

// size_t ft_strlen(char *str);
// char	*ft_strdup(char *str);
t_token	*add_node(t_token **list, t_token *node);
t_token	*creat_node(char *str);

//errors
// int check_unclosed_q(char *str);
int check_error(char *str);

void sigint_handler (int signo);
void handle_signals();
int is_between_quotes(char *line, int index);
int is_space(char c);
void remove_quotes(char **line);
#endif
