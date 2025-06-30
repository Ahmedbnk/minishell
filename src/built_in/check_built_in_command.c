#include "minishell.h"

/*void execute_builtin(t_shell_control_block *shell)
{
  int status;
  if(are_they_equal(*shell->cmd_and_args, "pwd"))
  {
    printf("%s\n", pwd(&status));
    shell->exit_status = status;
  }
  else if(are_they_equal(*shell->cmd_and_args, "env"))
    shell->exit_status = print_env(shell->env_cpy);
  else if(are_they_equal(*shell->cmd_and_args, "echo"))
    shell->exit_status = echo(shell->cmd_and_args);
  else if(are_they_equal(*shell->cmd_and_args, "cd"))
    shell->exit_status = cd(shell->env_cpy, shell->cmd_and_args);
  else if(are_they_equal(*shell->cmd_and_args, "export"))
    shell->exit_status = export(shell, shell->cmd_and_args +1);
  else if(are_they_equal(*shell->cmd_and_args, "unset"))
    shell->exit_status = unset(&shell->env_cpy, shell->cmd_and_args +1);
  else if(are_they_equal(*shell->cmd_and_args, "exit"))
    exit(0);
}*/

/*void save_original_fds(t_shell_control_block *shell)
{
  shell->original_stdin = dup(0);
  shell->original_stdout = dup(1);
}*/

/*void restore_original_fds(t_shell_control_block *shell)
{
  dup2(shell->original_stdin, 0);
  dup2(shell->original_stdout, 1);
  close(shell->original_stdin);
  close(shell->original_stdout);
}*/

/*void init_redirection_vars(t_shell_control_block *shell)
{
  shell->in_file_name = NULL;
  shell->file_name = NULL;
}*/

// int check_ambiguous_redirection(t_shell_control_block *shell)
// {
//   if (shell->file_name_lst && shell->file_name_lst->status == AMBIGUOUS)
//   {
//     print_error("ambig\n");
//     shell->exit_status = 1;
//     return 1;
//   }
//   return 0;
// }

// void advance_file_name_list(t_shell_control_block *shell)
// {
//   if (shell->file_name_lst)
//     shell->file_name_lst = shell->file_name_lst->next;
// }

// void process_redirection_tokens(t_shell_control_block *shell)
// {
//   if (shell->tokenze->type == HEREDOC)
//     shell->in_file_name = shell->tokenze->heredoc_file_name;
//   else if (shell->tokenze->type == REDIR_IN)
//     handle_redir_in((shell->tokenze->next)->word, &(shell->in_file_name));
//   else if (shell->tokenze->type == REDIR_OUT)
//     handle_redir_out((shell->tokenze->next)->word, &(shell->file_name));
//   else if (shell->tokenze->type == REDIR_APPEND)
//     handle_append((shell->tokenze->next)->word, &(shell->file_name));
// }

// int parse_redirections(t_shell_control_block *shell)
// {
//   t_token *original_tokenized;

//   original_tokenized = shell->tokenze;
//   while (shell->tokenze && shell->tokenze->word != NULL && shell->tokenze->type != PIPE)
//   {
//     if (is_redirection(shell->tokenze->word))
//     {
//       if (check_ambiguous_redirection(shell))
//       {
//         shell->tokenze = original_tokenized;
//         return 1;
//       }
//       advance_file_name_list(shell);
//     }
//     process_redirection_tokens(shell);
//     shell->tokenze = shell->tokenze->next;
//   }
//   shell->tokenze = original_tokenized;
//   return 0;
// }

// void setup_output_redirection(t_shell_control_block *shell)
// {
//   if (shell->file_name)
//   {
//     shell->fd_out = open(shell->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
//     dup2(shell->fd_out, 1);
//     close(shell->fd_out);
//   }
// }

// void setup_input_redirection(t_shell_control_block *shell)
// {
//   if (shell->in_file_name)
//   {
//     shell->fd_in = open(shell->in_file_name, O_RDONLY);
//     dup2(shell->fd_in, 0);
//     close(shell->fd_in);
//   }
// }

// void execute_parent_builtin(t_shell_control_block *shell)
// {
//   save_original_fds(shell);
//   init_redirection_vars(shell);
//   if (parse_redirections(shell))
//     shell->exit_status = 1;
//   setup_output_redirection(shell);
//   setup_input_redirection(shell);
//   execute_builtin(shell);
//   restore_original_fds(shell);
// }
