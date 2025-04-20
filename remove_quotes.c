#include "minishell.h"

static void remove_quotes_helper(char *line, char **parsed_quote_line)
{
  int i = 0;
  int j = 0;
  char quote = 0;

  while (line[i])
  {
    if ((line[i] == single_q || line[i] == double_q) && quote == 0)
      quote = line[i];
    else if ((line[i] == single_q || line[i] == double_q) && quote == line[i])
      quote = 0;
    else
    {
      (*parsed_quote_line)[j] = line[i];
      j++;
    }
    i++;
  }
  (*parsed_quote_line)[j] = '\0';
}

void remove_quotes(char **line)
{
  char *parsed_quote_line = malloc(ft_strlen(*line) + 1);
  if (!parsed_quote_line)
    return ;

  remove_quotes_helper(*line, &parsed_quote_line);
  free(*line);
  *line = parsed_quote_line;
}

