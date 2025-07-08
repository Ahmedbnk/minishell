/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <abenkrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:52:52 by abenkrar          #+#    #+#             */
/*   Updated: 2025/07/04 17:52:52 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define SIZE 4096

char	*pwd(int *status)
{
  char *str = ft_getenv("PWD");
  *status = 0;
  char	*buffer;

  if(removed_file_flag(-1))
  {
    print(2, PWD_ERROR);
    *status = 1;
    return NULL;
  }
  buffer = ft_malloc(SIZE, 1);
  if (getcwd(buffer, SIZE) != NULL)
    return buffer;
  else if(str)
    return str;
  return NULL;
}
