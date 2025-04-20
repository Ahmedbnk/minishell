#include "minishell.h"

int main()
{
    char *line;

    while(1)
    {
        handle_signals();
        line = readline(">>>> ");
        if(line && *line)
            add_history(line);
        if(line == NULL)
            return 0;
        check_error(line);
    }
    return 0;
}
//some errors messages 
//  syntax error near unexpected token `|'
// syntax error near unexpected token `newline'
