void expand_if_possible(char **string)
{
  int i = 0;
  char *str = *string;
  while(str[i])
  {
    if(str[i] == '$' && should_i_expand(str, i))
    {
      expand(string, &i);
      str = *string;
    }
    i++;
  }
}
