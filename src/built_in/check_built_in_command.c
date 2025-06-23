#include "minishell.h"

int execute_built_in_command(t_shell_control_block *shell)
{
    if(are_they_equal(*shell->cmd_and_args, "pwd"))
      return ((printf("%s\n",pwd()), 1));
    else if(are_they_equal(*shell->cmd_and_args, "env"))
      return ((print_env(shell->env_cpy), 1));
    else if(are_they_equal(*shell->cmd_and_args, "echo"))
      return ((echo(shell->cmd_and_args), 1));
    else if(are_they_equal(*shell->cmd_and_args, "cd"))
      return ((cd(shell->env_cpy, shell->cmd_and_args), 1));
    else if(are_they_equal(*shell->cmd_and_args, "export"))
      return((export(shell, shell->cmd_and_args +1),1));
    else if(are_they_equal(*shell->cmd_and_args, "unset"))
      return((unset(&shell->env_cpy, shell->cmd_and_args +1),1));
  return 0;
}

int  execute_built_in(t_shell_control_block *shell, int state)
{
  int result;
  if (state == 1)
  {
    int original_stdin = dup(0);
    int original_stdout = dup(1);
    t_token *original_tokenized = shell->tokenze;
    shell->in_file_name = NULL;
    shell->file_name = NULL;
    while (shell->tokenze && shell->tokenze->word != NULL && shell->tokenze->type != PIPE)
    {
      if(is_redirection(shell->tokenze->word))
      {
        if(shell->file_name_lst && shell->file_name_lst->status == AMBIGUOUS)
        {
          print_error("ambig\n");
          return 1;
        }
        if(shell->file_name_lst)
          shell->file_name_lst = shell->file_name_lst->next;
      }
      if (shell->tokenze->type == HEREDOC)
        shell->in_file_name = shell->tokenze->heredoc_file_name;
      else if (shell->tokenze->type == REDIR_IN)
        handle_redir_in((shell->tokenze->next)->word, &(shell->in_file_name));
      else if (shell->tokenze->type == REDIR_OUT)
        handle_redir_out((shell->tokenze->next)->word, &(shell->file_name));
      else if (shell->tokenze->type == REDIR_APPEND)
        handle_append((shell->tokenze->next)->word, &(shell->file_name));
      shell->tokenze =shell->tokenze->next;
    }
    shell->tokenze = original_tokenized;
    if (shell->file_name)
    {
      shell->fd_out = open(shell->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
      dup2(shell->fd_out, 1);
      close(shell->fd_out);
    }
    if(shell->in_file_name)
    {
      shell->fd_in = open(shell->in_file_name, O_RDONLY);
      dup2(shell->fd_in, 0);
      close(shell->fd_in);
    }
    result = execute_built_in_command(shell);
    dup2(original_stdin, 0);
    dup2(original_stdout, 1);
    close(original_stdin);
    close(original_stdout);
    return result;
  }
  else
  return execute_built_in_command(shell);
}
