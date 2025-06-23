
#include "minishell.h"

t_type	get_token_type(const char *str)
{
	if (are_they_equal(str, "|"))
		return (PIPE);
	else if (are_they_equal(str, "<"))
		return (REDIR_IN);
	else if (are_they_equal(str, ">"))
		return (REDIR_OUT);
	else if (are_they_equal(str, ">>"))
		return (REDIR_APPEND);
	else if (are_they_equal(str, "<<"))
		return (HEREDOC);
	else
		return (WORD);
}

// void fill_the_list(t_token * list, char **arr)
// {
//   int i;
//   i = 0;
//   while(arr[i])
//   {
//     list[i].type = get_token_type(arr[i]);
//     list[i].word = ft_strdup(arr[i], 1);
//     i++;
//   }
//     list[i].word = 0;
//     list[i].type = -1;
// }


// int check_syntax_error(t_shell_control_block *sh)
// {
//   int i; i = 0;
//   while(i < len)
//   {
//     if(data[i].type == PIPE && (i == 0 || len - 1 == i))
//       return((print_error("error near | \n"), 1));
//     else if (data[i].type != PIPE && data[i].type != WORD && data[i + 1].type == PIPE)
//       return((print_error("error near | \n"), 1));
//     else if (data[i].type != PIPE && data[i].type != WORD && data[i + 1].type != WORD)
//       return((print_error("error near new line \n"), 1));
//     else if (data[i].type != PIPE && data[i].type != WORD && len -1 == i)
//       return((print_error("error near new line \n"), 1));
//     i++;
//   }
//   return 0;
// }

int	check_syntax_error(t_shell_control_block *sh)
{
	t_token	*ptr;

	ptr = sh->tokenze;
	while (ptr)
	{
		if (ptr->type == PIPE && (!sh->tokenze->next || !ptr->next))
			return (print_error("error near | \n"), 1);
		if (ptr->type != PIPE && ptr->type != WORD && ptr->next
			&& ptr->next->type == PIPE)
			return (print_error("error near | \n"), 1);
		if (ptr->type != PIPE && ptr->type != WORD && ptr->next
			&& ptr->next->type != WORD)
			return (print_error("error near new line \n"), 1);
		if (ptr->type != PIPE && ptr->type != WORD && !ptr->next)
			return (print_error("error near new line \n"), 1);
		ptr = ptr->next;
	}
	return (0);
}
