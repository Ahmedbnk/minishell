
#include "minishell.h"

size_t ft_strlen(char *str)
{
    size_t i = 0;
    while(str[i])
        i++;
    return i;
}

char	*ft_strdup(char *str)
{
	int i;
    char *cpy;

	if (!str)
		return (NULL);
	i = 0;
    cpy = malloc((ft_strlen(str) + 1));
    if(!cpy)
        return NULL;
    while(str[i])
    {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return cpy;
}

t_token	*creat_node(char *str)
{
	t_token *node;
	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->word = ft_strdup(str);
	node->type = 0;
	node->next = NULL;
	return (node);
}

t_token	*add_node(t_token **list, t_token *node)
{
    t_token *ptr;

    ptr = *list;
    if(!node) 
        return NULL;
    if(!*list)
    {
        *list = node;
        return (*list);
    }
    while(ptr->next)
        ptr = ptr->next;
    ptr->next = node;
    return (*list);
}

void clear_list(t_token **list)
{
    t_token *ptr;

    ptr = *list;
    while(ptr)
    {
        ptr = ptr->next;
        free((*list)->word);
        free(*list);
        *list = ptr;
    }
}
