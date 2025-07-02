#include "minishell.h"

int my_exit(char **args)
{
  if(len_of_two_d_array(args) == 0)
    return 0;
  long long result = 0;
  if(!check_is_valid_number(*args))
  {
    print(2, buffering("exit: ", *args , ": numeric argument required\n"));
    return (2);
  }
  else if(*(args + 1))
  {
    print(2,"exit: too many arguments\n");
    return (1);
  }
  result = ft_atol(*args);
  return ((int )(result % 256));
}
