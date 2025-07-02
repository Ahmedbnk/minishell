#include "minishell.h"

void	skip_command(t_token **tokenized_address)
{
	t_token	*tokenze;
	tokenze = *tokenized_address;
	while (tokenze && tokenze->word != NULL && tokenze->type != PIPE)
		tokenze = tokenze->next;
	*tokenized_address = tokenze;
}
