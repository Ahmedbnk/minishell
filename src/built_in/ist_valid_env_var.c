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

int is_valid_var(t_shell_control_block *s, char *str)
{
    int i;
    i = 0;
    if(!ft_isalpha(str[0]) && str[0] != '_')
    {
        printf("export: '%s' : not a valid identifier\n", str);
        s->exit_status = 1;
        return 0;
    }
    while(str[i] && str[i] != '=')
    {
        if(!ft_isalpha(str[i]) && str[i] != '_' && ft_isdigit(str[i]))
        {
    printf("test2\n");
            printf("export: '%s' : not a valid identifier\n", str);
            s->exit_status = 1;
            return 0;
        }
        i++;
    }
    return 1;
}

int compare_env_var(char *var1, char *var2)
{
  int i ;
  i = 0;
  while((var2[i] && var2[i] != '=') || var1[i] != '=' )
  {
    if(var1[i] != var2[i])
      return 0;
    i++;
  }
  return 1;
}
