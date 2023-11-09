/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/09 19:08:08 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

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

/* int	main(void)
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
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
} */
