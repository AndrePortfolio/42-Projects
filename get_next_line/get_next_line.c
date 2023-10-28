/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:52:28 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/28 21:29:45 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	int		bytes;
	char	*buffer;
	int		i;
	int		c;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = read(fd, &c, 1);
	i = 0;
	while (bytes > 0)
	{
		buffer[i] = c;
		if (c == '\n' || c == '\0')
			break ;
		bytes = read(fd, &c, 1);
		i++;
	}
	if (i == 0 || bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	path[] = "test.txt";
	char	*str;
	int		i = 0;

	fd = open(path, O_RDONLY);
	while (i < 10)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("line%i: %s\n", i, str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
