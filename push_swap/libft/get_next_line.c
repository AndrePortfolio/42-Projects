/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:25:16 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/07 12:29:39 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(int *nl_finder, char *buffer);
static size_t	ft_strlen(const char *s);
static char		*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	buffer[FILE_NBR][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			nl_finder;

	i = 0;
	nl_finder = 1;
	line = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= FILE_NBR)
	{
		if (fd > 0 && read(fd, 0, 0) >= 0 && fd < FILE_NBR)
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

static void	ft_free(int *nl_finder, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (!*nl_finder)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			*nl_finder = 0;
		buffer[i++] = '\0';
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		tlenght;
	char	*n_str;

	i = 0;
	j = 0;
	tlenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	n_str = (char *)malloc(sizeof(char) * tlenght);
	if (!n_str)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		n_str[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	n_str[i + j] = '\0';
	free(s1);
	return (n_str);
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
