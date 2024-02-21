/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:33 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/21 22:15:33 by andre-da         ###   ########.fr       */
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

int	count(t_map *map, char chr, int y, int x)
{
	int	count;

	count = 0;
	if (chr == PLAYER)
	{
		map->player_x = x;
		map->player_y = y;
	}
	count += 1;
	return (count);
}

bool	check_characters(t_map *map, int exit, int collect, int space)
{
	int	player;
	int	y;
	int	x;

	y = -1;
	player = 0;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == PLAYER)
				player += count(map, PLAYER, y, x);
			else if (map->map[y][x] == EXIT)
				exit += count(map, EXIT, y, x);
			else if (map->map[y][x] == COLLECTIBLE)
				collect += count(map, COLLECTIBLE, y, x);
			else if (map->map[y][x] == EMPTY)
				space += count(map, EMPTY, y, x);
			else if (!ft_strchr("PEC01", map->map[y][x]))
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
