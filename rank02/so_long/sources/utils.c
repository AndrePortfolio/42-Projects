/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:08:50 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 01:30:42 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	find_collectible(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == COLLECTIBLE)
				return (true);
			x++;
		}
		y++;
	}
	return (false);
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
