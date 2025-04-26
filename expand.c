#include "minishell.h"

char *expand(char *str)
{
  int i = 0;
  char *container = ft_strdup("");
  char *tmp;
  char *befor_dollar;
  char *to_expand;
  char *env_value;

  while (str[i])
  {
    tmp = container;
    befor_dollar = dup_befor_dollar(str + i, &i);
    container = ft_strjoin(container, befor_dollar);
    free(tmp);
    free(befor_dollar);

    if (str[i] == '$')
    {
      to_expand = what_to_expand(str, &i);
      env_value = get_env_value(to_expand);
      free(to_expand);
      tmp = container;
      container = ft_strjoin(container, env_value);
      free(tmp);
      free(env_value);
    }
  }
  return container;
}
