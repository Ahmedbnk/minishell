
#include "minishell.h"

typedef enum
{
    index1 = 0,
} int_t;


int are_they_equal(char *str1, char *str2)
{
    int i;
    i = 0;
    while(str1[i] || str2[i])
    {
        if(str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    int_t index1;

    if(are_they_equal("hello", "hello"))
        printf("nice the are equal\n");
    else
        printf("they are not equal\n");
    printf("%d\n", index1);
    return 0;
}