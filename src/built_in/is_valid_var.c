#include "minishell.h"

int is_valid_var(char *str)
{
    int i;
    i = 0;
    if(!ft_isalpha(str[0]) && str[0] != '_')
    {
        printf("export: '%s' : not a valid identifier\n", str);
        return 0;
    }
    while(str[i] && str[i] != '=')
    {
        if(!ft_isalpha(str[i]) && str[i] != '_' && ft_isdigit(str[i]))
        {
            printf("export: '%s' : not a valid identifier\n", str);
            return 0;
        }
        i++;
    }
    return 1;
}
