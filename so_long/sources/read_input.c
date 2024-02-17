/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:18:53 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/17 17:39:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_map *map, int fd, int rows)
{
	char *line;
	char *trimmed_line;
	int length;

	line = get_next_line(fd);
	if (!line && rows == 0)
		error_message("Map is empty");
	else if (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		length = ft_strlen(trimmed_line);
		map->map[rows] = malloc(sizeof(char) * (length + 1));
		if (!map->map[rows])
			free_map(map, "Memory allocation error", 1);
		ft_strlcpy(map->map[rows], trimmed_line, length + 1);
		free(line);
		free(trimmed_line);
		read_map(map, fd, rows + 1);
	}
	else
		map->map[rows] = NULL;
}

bool	is_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i] || ft_strlen(str + i) > 4)
		return (false);
	if (str[i] == '.')
	{
		if (!ft_strncmp(str + i, ".ber", 4))
			return (true);
	}
	return (false);
}

bool	is_rectangular(t_map	*map)
{
	int	row = 0;
	int	coll;
	int	length = 0;

	while (map->map[row])
	{
		coll = 0;
		while (map->map[row][coll])
			coll++;
		if (length != coll && length != 0)
			return (false);
		length = coll;
		row++;
	}
	map->cols = coll;
	map->rows = row;
	return (true);
}

bool	around_walls(t_map	*map)
{
	int row = 0;
	int	coll = 0;

	while (map->cols > coll)
	{
		if (map->map[0][coll] != '1' || map->map[map->rows - 1][coll] != '1')
			return (false);
		coll++;
	}
	while (map->rows > row)
	{
		if (map->map[row][0] != '1' || map->map[row][map->cols - 1] != '1')
			return (false);
		row++;
	}
	return (true);
}

void	read_input(t_map *map, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error_message("Invalid number of arguments");
	if (!is_ber(argv[1]))
		error_message("Invalid file format, must be .ber file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Failed to open map");
	read_map(map, fd, 0);
	close(fd);
	if (!is_rectangular(map))
		error_message("Map must be rectangular");
	if (!around_walls(map))
		error_message("Map must be surrounded by walls");


}
