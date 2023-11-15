/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/15 17:59:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **rest);

char	*get_next_line(int fd)
{
	static char	*rest_line;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !rest_line)
		return (NULL);
	temp = ft_strchr(rest_line, '\n');
	bytes_read = 1;
	while (!rest_line || !temp)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		rest_line = ft_strjoin(rest_line, buffer);
	}
	if (bytes_read == 0 && !rest_line)
	{
		free(rest_line);
		return (NULL);
	}
	return (get_line(&rest_line));
}

static char	*get_line(char **rest)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	while ((*rest)[i] != '\0' && (*rest)[i] != '\n')
		i++;
	line = ft_strdup(*rest);
	if ((*rest)[i] == '\n')
	{
		temp = ft_strdup(*rest + i + 1);
		free(*rest);
		*rest = temp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
	}
	return (line);
}
