#include "minishell.h"

void second_range(int exit_status)
{
  if (exit_status == 13)
    printf("Broken pipe\n");
  else if (exit_status == 15)
    printf("Alarm clock\n");
  else if (exit_status == 16)
    printf("Stack fault\n");
  else if (exit_status == 17)
    printf("Child exited\n");
  else if (exit_status == 18)
    printf("Continued\n");
  else if (exit_status == 19)
    printf("Stopped\n");
  else if (exit_status == 20 || exit_status == 21 || exit_status == 22)
    printf("Stopped\n");
  else if (exit_status == 24)
    printf("CPU time limit exceeded (core dumped)\n");
  else if (exit_status == 25)
    printf("File size limit exceeded (core dumped)\n");
  else if (exit_status == 26)
    printf("Virtual timer expired\n");
}
