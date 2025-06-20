#include "minishell.h"

static void	rm_quotes_from_multi_str_helper(char *line, char **parsed_quote_line,char *quote)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if((line[i] == single_q || line[i] == double_q) && *quote ==0)
			*quote = line[i];
		else if ((line[i] == single_q || line[i] == double_q)
			&& *quote == line[i])
			quote = 0;
		else 
			(*parsed_quote_line)[j++] = line[i];
		i++;
	}
	(*parsed_quote_line)[j] = '\0';
}
static void	rm_quotes_from_one_str_helper(char *line, char **parsed_quote_line)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (line[i])
	{
		if((line[i] == single_q || line[i] == double_q) && quote == 0)
			quote = line[i];
		else if ((line[i] == single_q || line[i] == double_q)
			&& quote == line[i])
			quote = 0;
		else 
			(*parsed_quote_line)[j++] = line[i];
		i++;
	}
	(*parsed_quote_line)[j] = '\0';
}

void	 rm_quotes_from_multi_str(char **line, char *quote)
{
	char	*line_without_quotes;

	line_without_quotes = ft_malloc(ft_strlen(*line) + 1, 1);
	rm_quotes_from_multi_str_helper(*line, &line_without_quotes, quote);
	*line = line_without_quotes;
}

void	rm_quotes_from_one_str(char **line)
{
	char	*line_without_quotes;

	line_without_quotes = ft_malloc(ft_strlen(*line) + 1, 1);
	rm_quotes_from_one_str_helper(*line, &line_without_quotes);
	*line = line_without_quotes;
}
