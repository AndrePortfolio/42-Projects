/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:33 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/19 21:18:42 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	count(t_map *map, char chr, int i, int j)
{
	int	count;

	count = 0;
	if (chr == PLAYER)
	{
		map->player.x = i;
		map->player.y = j;
	}
	count += 1;
	return (count);
}

bool	check_characters(t_map *map, int exit, int collect, int space)
{
	int	player;
	int	i;
	int	j;

	i = -1;
	player = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == PLAYER)
				player += count(map, PLAYER, i, j);
			else if (map->map[i][j] == EXIT)
				exit += count(map, EXIT, i, j);
			else if (map->map[i][j] == COLLECTIBLE)
				collect += count(map, COLLECTIBLE, i, j);
			else if (map->map[i][j] == EMPTY)
				space += count(map, EMPTY, i, j);
			else if (!ft_strchr("PEC01", map->map[i][j]))
				return (false);
		}
	}
	map->collect_nbr = collect;
	if (player != 1 || exit != 1 || space == 0 || collect == 0)
		return (false);
	map->exit_nbr = 1;
	return (true);
}

void	player_access(t_map *map, char **visited, int x, int y)
{
	if (visited[x][y] == VISITED || visited[x][y] == WALL)
		return ;
	if (visited[x][y] == COLLECTIBLE)
		map->collect_nbr -= 1;
	else if (visited[x][y] == EXIT)
		map->exit_nbr -= 1;
	visited[x][y] = VISITED;
	player_access(map, visited, x + 1, y);
	player_access(map, visited, x - 1, y);
	player_access(map, visited, x, y + 1);
	player_access(map, visited, x, y - 1);
}
