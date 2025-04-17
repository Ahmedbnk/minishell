
#include "minishell.h"

// function that divide the command line

void divide_command_line(char *line)
{
    int i;
    if(!line)
        return;    
}
int main()
{
    t_token *list_of_tokens;

    char *line;
    while(1)
    {
        line = readline(">>>> ");
        if(line && *line)
            add_history(line);
        // divide_cmdl(line);
        printf("hfdfjljf%s\n", line);
    }
    return 0;
}
