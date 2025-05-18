/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:31:33 by abenkrar          #+#    #+#             */
/*   Updated: 2024/12/09 14:24:13 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_failure_and_eof(char *rest, char *buffer,
		ssize_t readed_bytes)
{
	free(buffer);
	if (readed_bytes < 0)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

static char	*creat_rest(int fd, char *rest)
{
	char	*buffer;
	ssize_t	readed_bytes;
	char	*rest_clean;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	readed_bytes = 1;
	while (ft_strchr(rest, '\n') == NULL && readed_bytes != 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes <= 0)
			return (handle_failure_and_eof(rest, buffer, readed_bytes));
		buffer[readed_bytes] = '\0';
		rest_clean = rest;
		rest = ft_strjoin(rest_clean, buffer);
		if (!rest)
		{
			free(buffer);
			free(rest_clean);
			return (NULL);
		}
		free(rest_clean);
	}
	free(buffer);
	return (rest);
}

static char	*creat_line(char **rest)
{
	char	*line;
	char	*rest_clean;
	char	*temp_rest;
	size_t	i;

	i = 0;
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	i++;
	line = ft_substr(*rest, 0, i);
	if (!line)
		return (NULL);
	rest_clean = *rest;
	temp_rest = ft_substr(rest_clean, i, ft_strlen(rest_clean) - i);
	if (!temp_rest)
	{
		free(rest_clean);
		free(line);
		return (NULL);
	}
	*rest = temp_rest;
	free(rest_clean);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*main_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!rest)
	{
		rest = malloc(1);
		rest[0] = '\0';
	}
	rest = creat_rest(fd, rest);
	if (!rest || *rest == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	main_line = creat_line(&rest);
	if (*rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	return (main_line);
}
