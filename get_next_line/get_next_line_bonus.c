/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/17 20:08:57 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			nl_finder;

	i = 0;
	nl_finder = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (fd >= 0 && BUFFER_SIZE > i)
			buffer[i++] = '\0';
		return (NULL);
	}
	while (nl_finder && (buffer[0] || read(fd, buffer, BUFFER_SIZE)))
	{
		line = ft_strjoin(line, buffer);
		ft_free(&nl_finder, buffer);
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int	argc, char	**argv)
{
	int		fd[argc - 1];
	char	*line;
	int		i = 0;

	if (argc <= 1)
	{
		write(1, "Write some arguments\n", 21);
		return (1);
	}
	while (i < (argc - 1))
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	line = get_next_line(fd[i]);
	while (line)
	{
		printf("i: %d\n", i);
		printf("Line: %s", line);
		line = get_next_line(fd[i++]);
		if (i == (argc - 1))
			i = 0;
	}
	while (!i)
		close(fd[i--]);
	return (0);
}
