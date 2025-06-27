#include "minishell.h"

char *remake_delimeter(t_shell_control_block *shell ,char *str)
{
  char *returned_str = ft_malloc(ft_strlen(str) + 1, 1);

  int i;
  int j;

  i = 0;
  j = 0;
  while(str[i])
  {
    if(str[i] == '$' && str[i + 1] == '$')
    {
      returned_str[j++] = str[i++];
      returned_str[j++] = str[i++];
    }
    else if(str[i] == '$' && (str[i + 1] == single_q || str[i + 1] == double_q) && !is_between_quotes(str, i))
      i ++;
    else
      returned_str[j++] = str[i++];
  }
  returned_str[j] = '\0';
  rm_quotes_from_one_str(shell, &returned_str);
  returned_str = ft_strjoin(returned_str, "\n");
  return returned_str;
}

void create_heredoc(t_shell_control_block *s ,t_token *tokenze)
{
  int fd;
  char *str = NULL;
  char *buffer = NULL;

  tokenze->heredoc_file_name = ft_strjoin("/tmp/", generate_random_name());
  tokenze->delimiter = remake_delimeter(s, (tokenze ->next) -> word);
  while(1)
  {
    write(1, "> ", 3);
    str = get_next_line(0);
    if(heredoc_signal_state(0))
      break;
    if(str == NULL)
    {
      print_error("warning: here-document delimited by end-of-file (wanted `%s')\n", tokenze->delimiter);
      break;
    }
    if(are_they_equal(str, tokenze->delimiter))
       break;
    str = expand_if_possible(s, str, 1);
    buffer = ft_strjoin(buffer, str);
  }
  if(heredoc_signal_state(0))
  {
    write(1,"\n", 1);
    return;
  }
  fd = open(tokenze->heredoc_file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
  write(fd,buffer,ft_strlen(buffer));
  close(fd);
}

void create_all_heredocs(t_shell_control_block *shell)
{
  heredoc_signal_state(2);
  t_token *ptr;

  ptr = shell->tokenze;
  while(ptr)
  {
    if(ptr -> type == HEREDOC)
    {
      handle_signals(2);
      create_heredoc(shell, ptr);
      if(heredoc_signal_state(0))
        return;
    }
	ptr = ptr->next;
  }
}
