/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/24 17:44:52 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FILE_NBR][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			nl_finder;

	i = 0;
	nl_finder = 1;
	line = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || FILE_NBR <= fd)
	{
		if (fd > 0 && fd < FILE_NBR && read(fd, 0, 0) >= 0)
			while (BUFFER_SIZE > i)
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	while (nl_finder && (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE)))
	{
		line = ft_strjoin(line, buffer[fd]);
		ft_free(&nl_finder, buffer[fd]);
		if (!line)
			return (NULL);
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int	argc, char	**argv)
// {
// 	int		fd[argc - 1];
// 	char	*line = NULL;
// 	int		i = 0;
// 	int		flag = 0;

// 	if (argc <= 1)
// 	{
// 		write(1, "Write some arguments\n", 21);
// 		return (1);
// 	}
// 	while (i < (argc - 1))
// 	{
// 		fd[i] = open(argv[i + 1], O_RDONLY);
// 		i++;
// 	}
// 	i = 0;
// 	int	array[argc - 1];

// 	while (flag != (argc - 1))
// 	{
// 		line = get_next_line(fd[i++]);
// 		if (!line)
// 		{
// 			if (i < argc && array[i] != 1)
// 			{
// 				printf("Line %d: (null)\n", i);
// 				array[i] = 1;
// 				flag++;
// 			}
// 		}
// 		else
// 			printf("Line %d: %s", i, line);
// 		if (i == (argc - 1))
// 			i = 0;
// 	}
// 	while (!i)
// 		close(fd[i--]);
// 	return (0);
// }
