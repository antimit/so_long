/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:21:33 by onosul            #+#    #+#             */
/*   Updated: 2024/10/27 12:28:41 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_line(int fd, char *buffer)
{
	char	*line;
	int		char_read;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	char_read = 1;
	while (!newline(buffer) && char_read > 0)
	{
		char_read = read(fd, line, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(line);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		line[char_read] = '\0';
		buffer = append_string(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*after_new_line(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (str_len(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*before_new_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	buffer = get_new_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = before_new_line(buffer);
	buffer = after_new_line(buffer);
	return (line);
}
