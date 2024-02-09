/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:49:04 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/08 21:34:43 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_bool	allocate_visited(t_map *map)
{
	int	ctd;

	map->visited = malloc(sizeof(t_bool *) * map->rows);			// Malloc visited based on the map rows
	if (map->visited == NULL)										// Protect the malloc
		return (FALSE);
	ctd = map->rows;												// Asigned the nbr of rows to ctd
	while (ctd--)													// Go through all rows
	{
		map->visited[ctd] = malloc(sizeof(t_bool) * map->cols);		// Malloc a t_bool to this collon in this row
		if (map->visited[ctd] == NULL)								// Protect the malloc
		{
			while (ctd < map->rows)									// If malloc fails, free previously allocated memory. (arrays)
				free(map->visited[ctd++]);
			free(map->visited);										// free array of arrays
			freemap(map, "Error allocating memory", 1);				// free map
		}
	}
	initialize_visited(map);										// Simply initialize it
	return (TRUE);
}

void	initialize_visited(t_map *map)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (ctd < map->rows)						// Go through each row
	{
		ctd2 = 0;
		while (ctd2 < map->cols)				// Go through each collon
		{
			map->visited[ctd][ctd2] = FALSE;	// Initialize visited to FALSE
			ctd2++;
		}
		ctd++;
	}
}

void	free_matrix(t_map *map, int i, int max)
{
	while (i <= max)
		free(map->visited[i++]);	// Free memory from arrays
	free(map->visited);				// Free memory from array of arrays
}

t_bool	flood_fill(t_map *map, int x, int y)
{
	if (map->map[x][y] == '1' || map->visited[x][y] == TRUE)	// If it is a wall or I have already checked this location
		return (FALSE);
	else
		map->visited[x][y] = TRUE;								// Set visited to TRUE
	if (map->map[x][y] == 'E')
		map->check.exit--;										// Fids all exits and intends to get to 0
	if (map->map[x][y] == 'C')
		map->check.collectibles--;								// Fids all collectables and intends to get to 0
	flood_fill(map, x + 1, y);									// recursively calls the function again to check every address in the matrix
	flood_fill(map, x - 1, y);									// recursively calls the function again to check every address in the matrix
	flood_fill(map, x, y + 1);									// recursively calls the function again to check every address in the matrix
	flood_fill(map, x, y - 1);									// recursively calls the function again to check every address in the matrix
	return (TRUE);
}

void	validate_map(t_map *map)
{
	int	ctd;
	int	ctd2;

	check_map(map);													// Checks if map has valid objects
	check_line(map);												// Check if map is rectangular
	ctd = -1;
	while (++ctd < map->rows)										// Go through each row
	{
		ctd2 = 0;
		while (ctd2 < map->cols)									// Go through each collon
		{
			if (map->map[ctd][ctd2] == 'P')							// Checks if this is the Player address
			{
				map->check.player_x = ctd;							// Assign x value (row) to player
				map->check.player_y = ctd2;							// Assign y value (collon) to player
			}
			if (ctd == 0 || ctd == map->rows - 1 || ctd2 == 0		// If it is on the exterior part of the map
				|| ctd2 == map->cols - 1)
			{
				if (map->map[ctd][ctd2] != '1')						// Unless there is 1 (walls) there, the program is invalid
					freemap(map, "Map must be surrounded by walls", 1);
			}
			ctd2++;
		}
	}
}
