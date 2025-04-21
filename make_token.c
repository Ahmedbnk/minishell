
#include "minishell.h"

token_t get_token_type(const char *str) {
    if (are_they_equal(str, "|"))
        return TOKEN_PIPE;
    else if (are_they_equal(str, "<"))
        return TOKEN_REDIR_IN;
    else if (are_they_equal(str, ">"))
        return TOKEN_REDIR_OUT;
    else if (are_they_equal(str, ">>"))
        return TOKEN_REDIR_APPEND;
    else if (are_they_equal(str, "<<"))
        return TOKEN_HEREDOC;
    // else if (are_they_equal((const char *)str, ""))
    //     return TOKEN_EOF;
    else
        return TOKEN_WORD;
}

void    get_data(t_token *data, char **spliteed)
{
    int i;
    i = 0;
    while(spliteed[i])
    { 
        data[i].type = get_token_type(spliteed[i]);
        data[i].word = spliteed[i];
        i++;
    }
}

// int main()
// {
//     t_token data[3];
//     char *str[] = {"hello", ">>" , "|", NULL};
//     get_data(data, str);

//     printf("%d\n", data[0].type);
//     printf("%d\n", data[1].type);
//     printf("%d\n", data[2].type);
// }