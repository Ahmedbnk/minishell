#include "minishell.h"

void print_exit_signal_message(int exit_status)
{
	int tmp;

  tmp = exit_status - 128;
  first_range(tmp);
  second_range(tmp);
  third_range(tmp);
}
