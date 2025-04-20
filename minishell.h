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

// #define T_COMMAND,     1   // Command type
// #define T_ARGUMENT     2   // Argument type
// #define T_REDIRECTION  3   // Redirection operator type (e.g., >, <)
// #define T_PIPE         4   // Pipe operator type (|)
// #define T_QUOTE        9   // Quote type (' or ")
// #define T_PARENTHESIS 10   // Parentheses type (())
// #define T_COMMENT     11   // Comment type (#)

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
