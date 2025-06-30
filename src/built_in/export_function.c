#include "minishell.h"

int export(t_shell_control_block *s, char **to_export)
{
    if(!to_export || !*to_export)
    {
        sort_env(s->env_of_export);
        return 0;
    }
    while(*to_export)
    {
        if(!is_valid_var(*to_export));
        else
        {
        if (find_and_update_var(s->env_of_export, *to_export));
        else
            s->env_of_export = add_var_to_env(s->env_of_export , *to_export);
        if(!is_it_key_value(*to_export))
            ;
        else if (find_and_update_var(s->env_cpy, *to_export));
        else
            s->env_cpy = add_var_to_env(s->env_cpy , *to_export);
        }
        to_export++;
    }
  return 0;
}
