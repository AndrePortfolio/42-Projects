/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:07:12 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 11:23:22 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				player += count_player(map, PLAYER, y, x);
			else if (ft_strchr("EC0", map->map[y][x]))
				count_others(ft_strchr("EC0", map->map[y][x]),
					&exit, &collect, &space);
			else if (!ft_strchr("PEC01", map->map[y][x]))
				return (false);
		}
	}
	if (player != 1 || exit != 1 || space == 0 || collect == 0)
		return (false);
	map->collect_nbr = collect;
	map->exit_nbr = 1;
	return (true);
}

int	count_player(t_map *map, char chr, int y, int x)
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

void	count_others(char *chr, int *exit, int *collect, int *space)
{
	if (ft_strncmp(chr, "E", 1) == 0)
		(*exit) += 1;
	else if (ft_strncmp(chr, "C", 1) == 0)
		(*collect) += 1;
	else if (ft_strncmp(chr, "0", 1) == 0)
		(*space) += 1;
}

