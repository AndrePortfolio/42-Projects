/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:34:07 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/18 21:41:09 by andrealbuqu      ###   ########.fr       */
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

int	count(t_map *map, char chr, int i, int j)
{
	int	count;

	count = 0;
	if (chr == 'P')
	{
		map->player.x = j;
		map->player.y = i;
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
			if (map->map[i][j] == 'P')
				player += count(map, 'P', i, j);
			else if (map->map[i][j] == 'E')
				exit += count(map, 'E', i, j);
			else if (map->map[i][j] == 'C')
				collect += count(map, 'C', i, j);
			else if (map->map[i][j] == '0')
				space += count(map, '0', i, j);
			else if (!ft_strchr("PEC01", map->map[i][j]))
				return (false);
		}
	}
	map->collect_nbr = collect;
	if (player != 1 || exit != 1 || space == 0 || collect == 0)
		return (false);
	return (true);
}

// bool	player_access(t_map *map, int x, int y)
// {

// 	while (/* condition */)
// 	{
// 		/* code */
// 	}
// 	if (!visited)
// 	{
// 	setpixel (x, y, fill_color);
// 	player_access(x+1, y, fill_color, old_color);
// 	player_access(x-1, y, fill_color, old_color);
// 	player_access(x, y+1, fill_color, old_color);
// 	player_access(x, y-1, fill_color, old_color);
// 	}
// }
