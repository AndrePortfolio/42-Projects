/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:33 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 20:59:29 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_rectangular(t_map	*map)
{
	int	row;
	int	coll;
	int	length;

	row = 0;
	length = 0;
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
	int	row;
	int	coll;

	row = 0;
	coll = 0;
	while (map->cols > coll)
	{
		if (map->map[0][coll] != WALL || map->map[map->rows - 1][coll] != WALL)
			return (false);
		coll++;
	}
	while (map->rows > row)
	{
		if (map->map[row][0] != WALL || map->map[row][map->cols - 1] != WALL)
			return (false);
		row++;
	}
	return (true);
}

void	player_access(t_map *map, char **visited, int x, int y)
{
	if (visited[y][x] == VISITED || visited[y][x] == WALL)
		return ;
	if (visited[y][x] == COLLECTIBLE)
		map->collect_nbr -= 1;
	else if (visited[y][x] == EXIT)
		map->exit_nbr -= 1;
	visited[y][x] = VISITED;
	player_access(map, visited, x + 1, y);
	player_access(map, visited, x - 1, y);
	player_access(map, visited, x, y + 1);
	player_access(map, visited, x, y - 1);
}
