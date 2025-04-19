
#include "minishell.h"

int check_unclosed_quotes(char *str)
{
    int i = 0;
    int single_quote = 0;
    int double_quote = 0;

    while (str[i])
    {
        if (str[i] == single_q && double_quote == 0)
            single_quote = !single_quote;
        else if (str[i] == double_q && single_quote == 0)
            double_quote = !double_quote;
        i++;
    }
    return (single_quote || double_quote);
}

int check_error(char *str)
{
    if(check_unclosed_quotes(str))
    {
        while(1)
        {
            readline("> ");
        }
        return 0;
    }
    return 1;
}
