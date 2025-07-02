#include "minishell.h"

int set_handler_state(int state)
{
  static int value;
  if(state != -1)
    value = state;
  return value;
}
