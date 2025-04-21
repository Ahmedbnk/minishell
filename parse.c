
#include "minishell.h"

//void remove_quotes(char *line, char **parsed_quote_line)
//{
//  int i = 0;
//  int j = 0;
//  char quote = 0;
//
//  while (line[i])
//  {
//    if ((line[i] == single_q || line[i] == double_q) && quote == 0)
//      quote = line[i];
//    else if ((line[i] == single_q || line[i] == double_q) && quote == line[i])
//      quote = 0;
//    else
//    {
//      (*parsed_quote_line)[j] = line[i];
//      j++;
//    }
//    i++;
//  }
//  (*parsed_quote_line)[j] = '\0';
//}


// int main()
// {
//   char *line = readline(">>> :");
//   char *parsed_quote_line = malloc(ft_strlen(line) + 1);
//   if (!parsed_quote_line)
//     return 1;

// //  remove_spaces(line, &parsed_quote_line);
// //  remove_quotes(line, &parsed_quote_line);
// //  printf("the parsed line is %s \n", parsed_quote_line);

//   //free(line);
//  // free(parsed_quote_line); 
//  int x = is_between_quotes(line, 5);
//  printf("%d\n", x);
//   return 0;
// }

