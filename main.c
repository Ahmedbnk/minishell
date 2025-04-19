
#include "minishell.h"

// function that divide the command line

// void divide_command_line(char *line)
// {
//     int i;
//     if(!line)
//         return;    
// }

int main()
{
//     t_token *list_of_tokens;

    char *line;
    while(1)
    {
        line = readline(">>>> ");
        if(line && *line)
            add_history(line);
        else if(*line == '\0')
            return 0;
        if(!check_error(line))
                readline(">");
        // divide_cmdl(line);
        printf("%s\n", line);
        
        // printf("%zu\n", ft_strlen("hkhkhkkkj"));
    }
    return 0;
}
//just atest
