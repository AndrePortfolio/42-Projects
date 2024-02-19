/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:36 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/19 16:27:56 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_map *map, int fd, int rows)
{
	char	*line;
	char	*trimmed_line;
	int		length;

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

char	**copy_map(t_map *map, char **original, int rows, int cols)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char*) * rows);
	if (!copy)
		free_map(map, "Memory allocation failed", 1);
	i = 0;
	while (i < rows)
	{
		copy[i] = malloc(sizeof(char) * cols + 1);
		if (!copy[i])
		{
			ft_free_a_array(copy);
			free_map(map, "Memory allocation failed", 1);
		}
		ft_strlcpy(copy[i], original[i], cols + 1);
		i++;
	}
	return (copy);
}

void	validate_map(t_map *map)
{
	char **visited;

	if (!is_rectangular(map))
		error_message("Map must be rectangular");
	if (!around_walls(map))
		error_message("Map must be surrounded by walls");
	if (!check_characters(map, 0, 0, 0))
		error_message("Invalid map metrics");
	visited = copy_map(map, map->map, map->rows, map->cols);
	player_access(map, visited, map->player.x, map->player.y);
	if (map->collect_nbr != 0 || map->exit != 0)
		error_message("Player can't access all collectibles and/or exit");
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
	validate_map(map);
}
