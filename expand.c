#include "minishell.h"
char *expand(char *str)
{
  int i;
  char *container;
  char *tmp;
  char *befor_dollar;
  char *to_expand;
  char *env_value;

  i = 0;
  container = ft_strdup("");
  befor_dollar = dup_befor_dollar(str, &i);
  tmp = container;
  container = ft_strjoin(container, befor_dollar);
  free(tmp);
  free(befor_dollar);
  
  while (str[i])
  {
    if (str[i] == '$')
    {
      to_expand = what_to_expand(str, &i);
      env_value = get_env_value(to_expand);
      free(to_expand);
      tmp = container;
      container = ft_strjoin(container, env_value);
      free(env_value);
      free(tmp);
      if(!str[i])
        return container;
      befor_dollar = dup_befor_dollar(str+i, &i);
      tmp = container;
      container = ft_strjoin(container, befor_dollar);
      free(tmp);
      free(befor_dollar);
    }
    else
      i++;
  }
  return container;
}
