#include "minishell.h"

typedef struct s_expand {
  char *befor_dollar;
  char *to_expand;
  char *after_expand;
  int last_one;
}t_expand;


void string_before_dollar(t_expand *data, int index, char *str, int *offset);
void string_to_expand(t_expand *data, int index, char *str, int *offset);
void string_after_expand(t_expand *data, int index, char *str, int *offset);

void allocat_expand_list(t_expand **expand_list, int how_much_to_expand)

{
  *expand_list = malloc(how_much_to_expand * sizeof(t_expand));
  if(!*expand_list)
    return;
}

void  init_expand_list(t_expand *expand_list, int how_much_to_expand)
{
  int i;
  i = 0;
  while(i < how_much_to_expand)
  {
    expand_list[i].befor_dollar= NULL;
    expand_list[i].to_expand= NULL;
    expand_list[i].after_expand= NULL;
    expand_list[i].last_one = 0;
    i++;
  }
}
void allocat_and_init(t_expand **expand_list, int how_much_to_expand)
{
  allocat_expand_list(expand_list, how_much_to_expand);
  init_expand_list(*expand_list, how_much_to_expand);
}

int how_many_dallar_to_expand(char *str)
{
  int i;
  int counter;
  counter = 0;
  i = 0;
  while(str[i])
  {
    if(str[i] == '$' && should_i_expand(str, i) && ft_isalnum(str[i+1]))
       counter++;
    i++;
  }
  return counter;
}



char *expnad_and_join_node(t_expand data)
{
  char *path;
  char *the_joined_node;
  char *rest;

  if(data.to_expand != NULL)
  {
    path = ft_strdup(getenv((data.to_expand)+1));
    the_joined_node= custom_join(data.befor_dollar, path);
    free(path);
  }
  if(data.last_one)
  {
    rest = custom_join(the_joined_node, data.after_expand);
    free(the_joined_node);
    return rest;
  }
  return the_joined_node;
}

char *new_str_after_expand(t_expand *data, int num_of_expantion)
{
    char *new_after_expand = NULL;
    char *expanded;
    char *joined;
    int i = 0;

    while (i < num_of_expantion)
    {
        if (num_of_expantion - i == 1)
            data[i].last_one = 1;
        expanded = expnad_and_join_node(data[i]);
        if (!expanded)
        {
            free(new_after_expand);
            return NULL;
        }
        joined = custom_join(new_after_expand, expanded);
        free(new_after_expand);
        free(expanded);
        new_after_expand = joined;
        if (!new_after_expand)
            return NULL;
        i++;
    }
    return new_after_expand;
}

void free_expand_list(t_expand *expand_list, int how_much_to_expand) {
    if (!expand_list)
        return;
    for (int i = 0; i < how_much_to_expand; i++) {
        free(expand_list[i].befor_dollar);
        free(expand_list[i].to_expand);
        free(expand_list[i].after_expand);
    }
    free(expand_list);
}

char *outline(char *str)
{
  int i;
  int offset;
  int num_of_expantion;
  char *new_str;
  t_expand *list;

  i = 0;
  offset = 0;
  num_of_expantion = how_many_dallar_to_expand(str);
  allocat_and_init(&list, num_of_expantion);
  while(i < num_of_expantion)
  {
      string_before_dollar(list , i, str, &offset);
      string_to_expand(list , i, str, &offset);
      string_after_expand(list , i, str, &offset);
    i++;
  }
  new_str = new_str_after_expand(list, num_of_expantion);
  free_expand_list(list, num_of_expantion);
  return new_str;
}


void string_before_dollar(t_expand *data ,int index, char *str, int *offset)
{
  int flag;

  if(!str)
    return;
  flag = *offset;

  while(str[*offset])
  {
    if(str[*offset] == '$' && should_i_expand(str, *offset) && ft_isalnum(str[(*offset)+1]))
      break;
    (*offset)++;
  }
  if(*offset > flag)
    data[index].befor_dollar = ft_substr(str, flag, *offset -flag);
  //printf("in str befor_dollar %s\n", data[index].befor_dollar);
}

void string_to_expand(t_expand *data, int index, char *str, int *offset)
{
  int start;

  if(!str)
    return;
  start = *offset;

  while(str[*offset])
  {
   if(str[*offset] == '$' && start == (*offset))
      (*offset)++;
    if(!ft_isalnum(str[(*offset)]) ||( str[*offset] == '$' && should_i_expand(str, *offset)))
      break;
    (*offset)++;
  }
  data[index].to_expand = ft_substr(str, start, *offset - start);
  //printf("to to_expand :  %s\n", data[index].to_expand);
}

void string_after_expand(t_expand *data, int index, char *str, int *offset)
{
  int start;
  int end;
  if(!str)
    return;
  start = *offset;
  end = *offset;

  while(str[end])
    end++;
  if(end > start)
    data[index].after_expand = ft_substr(str, start, end - start);
  //printf("after_expand :  %d %s\n", *offset , data[index].after_expand);
}

int main(void)
{
    char *line = "$a$GHHGFHGF$RHFHG$RHGFG$RFHGFG$RFGH";
    char *result;

  //  line = readline("$ ");
    //if (line)
     //   add_history(line);
    result = outline(line);
    if (result)
        printf("%s", result);
    free(result); // <--- FREE THE RESULT!
    printf("|end.");
    return 0;
}
