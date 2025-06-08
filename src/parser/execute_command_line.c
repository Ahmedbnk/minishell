#include "minishell.h"

int	generate_random_number(void)
{
  int	fd;
  int	random_number;

  fd = open("/dev/random", O_RDONLY);
  read(fd, &random_number, 4);
  close(fd);
  if (random_number < 0)
    return (-random_number);
  return (random_number);
}

char	*generate_random_name(void)
{
  int	num;

  num = generate_random_number();
  if (num < 0)
    return (NULL);
  return (ft_itoa(num));
}



void	skip_command(t_data **tokenized_address)
{
  t_data	*tokenized;

  tokenized = *tokenized_address;
  while (tokenized && tokenized->word != NULL && tokenized->type != PIPE)
    tokenized ++;
  *tokenized_address = tokenized;
}

void	print_command(t_data *tokenized)
{
  while (tokenized && tokenized->word != NULL && tokenized->type != PIPE)
  {
    printf("%s ", tokenized->word);
    tokenized ++;
  }
  printf("\n");
}

void handle_all_redir(t_shell_control_block *shell)
{
  while (shell->tokenized && shell->tokenized->word != NULL && shell->tokenized->type != PIPE)
  {
    if (shell->tokenized->type == HEREDOC)
      shell->in_file_name = shell->tokenized->heredoc_file_name;
    else if (shell->tokenized->type == REDIR_IN)
      handle_redir_in((shell->tokenized + 1)->word, &(shell->in_file_name));
    else if (shell->tokenized->type == REDIR_OUT)
      handle_redir_out((shell->tokenized + 1)->word, &(shell->file_name));
    else if (shell->tokenized->type == REDIR_APPEND)
      handle_append((shell->tokenized + 1)->word, &(shell->file_name));
    shell->tokenized ++;
  }

}
void	process_command(t_shell_control_block *shell)
{
  shell->in_file_name = NULL;
  shell->file_name = NULL;
  get_cmd_and_its_args(shell);
  handle_all_redir(shell);
    if (shell->file_name)
  {
    shell->fd_out = open(shell->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    dup2(shell->fd_out, 1);
    close(shell->fd_out);
  }
  if(shell->in_file_name)
  {
    shell->fd_in = open(shell->in_file_name, O_CREAT | O_RDONLY, 0644);
    dup2(shell->fd_in, 0);
    close(shell->fd_in);
  }
  if(!execute_built_in(shell))
    execute_command(shell);
  unlink(shell->in_file_name);
}

void execute_command_line_helper(t_shell_control_block *shell)
{
  int p_id = fork();
  if (p_id == 0)
  {
    if (shell->previous_read_end != -1)
    {
      dup2(shell->previous_read_end, 0);
      close(shell->previous_read_end);
    }
    if (shell->line_pointer && shell->line_pointer->type == PIPE)
    {
      close(shell->previous_read_end);
      close(shell->arr[0]);
      dup2(shell->arr[1], 1);
      close(shell->arr[1]);
    }
    process_command(shell);
    exit(0);
  }
  else
    shell->last_child_pid = p_id;
}
#include <stdio.h>

void print_exit_signal_message(int exit_status) {
  exit_status = exit_status - 128;
  if (exit_status == 1)
    printf("Hangup\n");
   else if (exit_status == 2)
     printf("\n");
  else if (exit_status == 3)
    printf("Quit (core dumped)\n");
  else if (exit_status == 4)
    printf("Illegal instruction (core dumped)\n");
  else if (exit_status == 5)
    printf("Trace/breakpoint trap (core dumped)\n");
  else if (exit_status == 6)
    printf("Aborted (core dumped)\n");
  else if (exit_status == 7)
    printf("Bus error (core dumped)\n");
  else if (exit_status == 8)
    printf("Floating point exception (core dumped)\n");
  else if (exit_status == 9)
    printf("Killed\n");
  else if (exit_status == 10)
    printf("User defined signal 1\n");
  else if (exit_status == 11)
    printf("Segmentation fault (core dumped)\n");
  else if (exit_status == 12)
    printf("User defined signal 2\n");
  else if (exit_status == 13)
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
    printf("Stopped (signal)\n");
  else if (exit_status == 20 || exit_status == 21 || exit_status == 22)
    printf("Stopped\n");
  else if (exit_status == 24)
    printf("CPU time limit exceeded (core dumped)\n");
  else if (exit_status == 25)
    printf("File size limit exceeded (core dumped)\n");
  else if (exit_status == 26)
    printf("Virtual timer expired\n");
  else if (exit_status == 27)
    printf("Profiling timer expired\n");
  else if (exit_status == 29)
    printf("I/O possible\n");
  else if (exit_status == 30)
    printf("Power failure\n");
  else if (exit_status == 31)
    printf("Bad system call (core dumped)\n");
  else if(exit_status == 32 || exit_status == 33)
    printf("Unknown signal %d\n", exit_status);
  else
    printf("Real-time signal %d\n", exit_status - 34);
}

void execute_command_line(t_shell_control_block *shell)
{
  int status;
  shell->line_pointer = shell->tokenized;
  shell->previous_read_end = -1;
  while (shell->line_pointer && shell->line_pointer->word)
  {
    shell->tokenized = shell->line_pointer;
    skip_command(&(shell->line_pointer));
    if (shell->line_pointer && shell->line_pointer->type == PIPE)
      pipe(shell->arr);
    execute_command_line_helper(shell);
    if (shell->previous_read_end != -1)
      close(shell->previous_read_end);
    if (shell->line_pointer && shell->line_pointer->type == PIPE)
    {
      close(shell->arr[1]);
      shell->previous_read_end =shell->arr[0];
      shell->line_pointer++;
    }
  }
  if (shell->previous_read_end != -1)
    close(shell->previous_read_end);

  waitpid(shell->last_child_pid, &status, 0);
  if (WIFEXITED(status))
    shell->exit_status = WEXITSTATUS(status);
  else if(WIFSIGNALED(status))
    shell->exit_status =  128 + WTERMSIG(status);
  else if(WIFSTOPPED(status))
    shell->exit_status = WSTOPSIG(status);
  if(shell->exit_status > 128)
    print_exit_signal_message(shell->exit_status);
  while (wait(NULL) > 0);
}
