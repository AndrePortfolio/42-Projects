/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:08:50 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 20:59:06 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
