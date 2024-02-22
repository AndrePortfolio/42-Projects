/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:36 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 01:30:37 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	validate_map(map);
}

void	read_map(t_map *map, int fd, int rows)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		read_map(map, fd, rows + 1);
	else
	{
		if (rows == 0)
			error_message("Empty file");
		map->map = ft_calloc((rows + 1), sizeof(char *));
		if (!map->map)
			error_message("Memory allocation failed");
		map->rows = rows;
	}
	if (line)
	{
		map->map[rows] = ft_strtrim(line, "\n");
		if (!map->map[rows])
			free_map(map, "Memory allocation failed", 1);
		free(line);
	}
}

void	validate_map(t_map *map)
{
	char	**visited;

	if (!is_rectangular(map))
		error_message("Map must be rectangular");
	if (!around_walls(map))
		error_message("Map must be surrounded by walls");
	if (!check_characters(map, 0, 0, 0))
		error_message("Invalid map metrics");
	visited = copy_map(map, map->map, map->rows);
	player_access(map, visited, map->player_x, map->player_y);
	if (visited)
		ft_free_a_array(visited);
	if (map->collect_nbr != 0 || map->exit_nbr != 0)
		error_message("Player can't access all collectibles and/or exit");
}

char	**copy_map(t_map *map, char **original, int rows)
{
	char	**copy;
	int		i;

	copy = ft_calloc(rows + 1, sizeof(char *));
	if (!copy)
		free_map(map, "Memory allocation failed", 1);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			ft_free_a_array(copy);
			free_map(map, "Memory allocation failed", 1);
		}
		i++;
	}
	return (copy);
}
