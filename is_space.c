#include "minishell.h"

int is_space(char c)
{
    if((c >= 9 && c <= 13) || c == 32)
        return 0;
    return 1;
}
