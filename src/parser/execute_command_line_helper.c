/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_line_helper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:01 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/11 07:28:39 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int *get_array_of_pids()
{
  static int *arr;
  int i;

  if(!arr)
  {
    i = 0;
    arr = ft_malloc(sizeof(int) * MAX_NUM_OF_PROC, 1);
    while (i < MAX_NUM_OF_PROC)
    {
      arr[i] = 0;
      i++;
    }
  }
  return arr;
}

void add_pid_to_array(int p_id)
{
  int *arr;
  int i;

  arr = get_array_of_pids();
  i = 0;
  while (i < MAX_NUM_OF_PROC && arr[i] != 0)
    i++;
  if (i < MAX_NUM_OF_PROC)
    arr[i] = p_id;
}

void kill_all(void)
{
  int *arr;
  int i;

  arr = get_array_of_pids();
  i = 0;
  while (i < MAX_NUM_OF_PROC && arr[i] != 0)
  {
    kill(arr[i], SIGKILL);
    i++;
  }
}

int ft_fork(void)
{
  int	p_id;

  p_id = fork();
  if (p_id < 0)
  {
    p_err("Fork failed");
		exit((kill_all(),free_all(), 1));
  }
  add_pid_to_array(p_id);
  return (p_id);
}

void	execute_command_line_helper(t_shell *shell)
{
	int	p_id;

	get_cmd_and_its_args(shell);
	p_id = ft_fork();
	if (p_id == 0)
	{
		signal(SIGINT, shell->old_sigint_handler);
		signal(SIGQUIT, shell->old_sigquit_handler);
		if (shell->previous_read_end != -1)
		{
			ft_dup2(shell->previous_read_end, 0);
			ft_close(shell->previous_read_end);
		}
		if (shell->line_pointer && shell->line_pointer->type == PIPE)
		{
			ft_close(shell->previous_read_end);
			ft_close(shell->arr[0]);
			ft_dup2(shell->arr[1], 1);
			ft_close(shell->arr[1]);
		}
		process_command(shell);
		exit((free_all(), exstat(-1)));
	}
	else
		shell->last_child_pid = p_id;
}
