#include "minishell.h"

int unset(char ***env, char **vars)
{
  while(*vars)
  {
    if(is_the_var_in_env(*env, *vars))
      remove_var_from_env(env, *vars);
    vars++;
  }
  return 0;
}

// int main(int argc, char *argv[], char *env[])
// {
//   (void ) argv;
//   (void ) argc;
//
//   char **env_cpy = copy_env(env);
//   char *av[] = {"b=1337", "jlj", "z=1337!","13=","a=45", NULL};
//   char *av1[] = {"b=1337", "a", "z=1337!","13=", NULL};
//   printf("%d\n", len_of_two_d_array(env_cpy));
//   export(&env_cpy, av);
//   printf("%d\n", len_of_two_d_array(env_cpy));
//   unset(&env_cpy,  av1);
//   print_env(env_cpy);
//      free_memory(*get_garbage_pointer());
//   return 0;
// }
//
