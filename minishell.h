#ifndef  MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

// #define T_COMMAND,     1   // Command type
// #define T_ARGUMENT     2   // Argument type
// #define T_REDIRECTION  3   // Redirection operator type (e.g., >, <)
// #define T_PIPE         4   // Pipe operator type (|)
// #define T_SEMICOLON    5   // Semicolon operator type (;)
// #define T_LOGICAL_AND  6   // Logical AND operator (&&)
// #define T_LOGICAL_OR   7   // Logical OR operator (||)
// #define T_BACKGROUND   8   // Background operator (&)
// #define T_QUOTE        9   // Quote type (' or ")
// #define T_PARENTHESIS 10   // Parentheses type (())
// #define T_COMMENT     11   // Comment type (#)

typedef struct s_token
{
    int type;
    char *word;
    struct s_token *next;
} t_token;

size_t ft_strlen(char *str);
char	*ft_strdup(char *str);
t_token	*add_node(t_token **list, t_token *node);
t_token	*creat_node(char *str);

#endif
