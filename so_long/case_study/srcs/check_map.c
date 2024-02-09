/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:45:31 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/08 20:00:35 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_map(t_map *map)
{
	int	ctd;
	int	ctd2;

	ctd = -1;															// Initialize ctd to -1 because of ++ctd (effectively 0)
	map->check.player = 0;												// Initialize check.player to 0
	map->check.exit = 0;												// Initialize check.exit to 0
	map->collectibles_count = 0;										// Initialize collectibles_count to 0
	while (map->map[++ctd])												// Run through the Matrix grid of characters in map.
	{
		ctd2 = -1;														// Initialize ctd2 to -1 because of ++ctd2 (effectively 0)
		while (map->map[ctd][++ctd2])									// Run through the Matrix grid of characters in map.
		{
			if (ft_strchr(LEGAL_CHARS, map->map[ctd][ctd2]) == NULL)	// Checks if all characters are valid for the map
				freemap(map, "Invalid character in map", 1);
			if (map->map[ctd][ctd2] == 'P')
				map->check.player++;									// Counts how many players are there based on P
			else if (map->map[ctd][ctd2] == 'E')
				map->check.exit++;										// Counts how many exits are there based on E
			else if (map->map[ctd][ctd2] == 'C')
				map->collectibles_count++;								// Counts how many collectibles are there based on C
		}
	}
	map_verefications(map);												// Makes sure the number of Players, Exits and collectibles is correct.
}

void	map_verefications(t_map *map)
{
	if (map->check.player != 1)
		freemap(map, "Invalid number of players", 1);		// Makes sure there is only 1 Player
	if (map->check.exit != 1)
		freemap(map, "Invalid number of exits", 1);			// Makes sure there is only 1 Exit
	if (map->collectibles_count < 1)
		freemap(map, "Invalid number of collectibles", 1);	// Makes sure there are atleast 2 collectibles
}
