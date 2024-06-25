/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakemrezeper <burakemrezeper@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:08:37 by ezeper            #+#    #+#             */
/*   Updated: 2024/06/25 02:53:16 by burakemreze      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *buffer, char *last)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (1)
	{
		bytes_read = read(fd, last, BUFFER_SIZE);
		last[bytes_read] = '\0';
		tmp = buffer;
		if (!buffer)
			buffer = ft_strjoin("", last);
		else
			buffer = ft_strjoin(tmp, last);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(last, '\n'))
			break ;
	}
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static char	*extract_line(char **lines)
{
	char	*left;
	char	*right;
	size_t	i;

	i = 0;
	while ((*lines)[i] != '\n' && (*lines)[i] != '\0')
		i++;
	if ((*lines)[i] == '\0')
		return (NULL);
	left = ft_substr(*lines, 0, i + 1);
	right = ft_strdup(*lines + i + 1);
	free(*lines);
	*lines = left;
	if (*right == '\0')
	{
		free(right);
		right = NULL;
	}
	return (right);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*last;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	last = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!last)
		return (NULL);
	line = read_buffer(fd, buffer, last);
	free(last);
	if (!line)
		return (NULL);
	buffer = extract_line(&line);
	return (line);
}
