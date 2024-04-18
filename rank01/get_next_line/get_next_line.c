/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/24 17:42:15 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		while (BUFFER_SIZE > i)
			buffer[i++] = '\0';
		return (NULL);
	}
	while (nl_finder && (buffer[0] || read(fd, buffer, BUFFER_SIZE)))
	{
		line = ft_strjoin(line, buffer);
		ft_free(&nl_finder, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int	argc, char	**argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc != 2)
// 	{
// 		write(1, "Write just one argument\n", 24);
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("Line: %s", line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
