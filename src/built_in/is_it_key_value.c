#include "minishell.h"

int is_it_key_value(char *str)
{
    while(*str)
    {
        if(*str == '=')
            return 1;
        str++;
    }
    return 0;
}
