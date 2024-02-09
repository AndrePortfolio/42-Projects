/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:39 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/08 21:45:28 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_line(t_map *map)
{
	int	ctd;

	map->cols = ft_strlen(map->map[0]);							// Finds lenght of collon 0
	ctd = 0;
	while (ctd < map->rows)										// Goes through every row
		if (ft_strlen(map->map[ctd++]) != (size_t)map->cols)	// Checks if there is a collon with a different size to collon 0
			freemap(map, "Map must be rectangular", 1);			// If it has a different size, invalid.
}

void	read_map(t_map *map, int count, int fd)
{
	char	*line;

	line = get_next_line(fd);								// Reads first line from fd into line.
	if (line != NULL)
		read_map(map, count + 1, fd);						// if succesfull calls the function again, used count to keep track of line nbr.
	else													// if no more lines
	{
		if (count == 0)										// in case no lines were read declare it as empty.
			error_message("Empty file");
		map->map = malloc(sizeof(char *) * (count + 1));	// Dinamically allocate memory for the map
		if (map->map == NULL)
			error_message("Error allocating memory");		// Protect malloc
		map->rows = count;									// Assigned the number or rows.
	}
	if (line)												// In case a line was read in this call
	{
		map->map[count] = ft_strtrim(line, "\n");			// Trim the \n at the end of each line.
		free(line);											// Line no longer useful, free memory from get_next_line.
	}
	else													// In case this is the last call and no line was read.
		map->map[count] = NULL;
}

void	initiate_flood(t_map *map)
{
	if (map->map[map->check.player_x][map->check.player_y] == 'P')	// If x & y are correctly determining where player is
	{
		allocate_visited(map);										// Creates a bool on the map matrix to check if I have checked that x, y (later)
		map->check.collectibles = map->collectibles_count;			// Initialize check.collectibles to the nbr of collectibles.
		flood_fill(map, map->check.player_x, map->check.player_y);	// Checks the whole matrix (set visited to TRUE)
		free_matrix(map, 0, map->rows - 1);							// Frees the matrix
		if (map->check.collectibles != 0 || map->check.exit != 0)	// If it failed to check the whole matrix, frees map with error.
			freemap(map, "Exit or collectibles not reachable", 1);
	}
}



void	read_input(int argc, char **argv, t_map *map)
{
	int	input_len;
	int	fd;

	if (argc != 2)
		error_message("Invalid number of arguments");							// Arguments must be 2: ./so_long && x.ber
	input_len = ft_strlen(argv[1]);												// used to check if param 2 is a ber file.
	if (input_len < 5 || ft_strncmp(argv[1] + input_len - 4, ".ber", 4) != 0)	// In the string goes to the address of . and checks if ber comes after
		error_message("Invalid file, must be a .ber file");						// Closes program if it aint a .ber
	fd = open(argv[1], O_RDONLY);												// If successful reads it into a File descriptor
	if (fd < 0)
		error_message("Error opening file");									// If there is an error opening, close.
	read_map(map, 0, fd);														// Reads map data from the fd and stores it in the 'map' structure
	close(fd);																	// fd no longer useful, close.
	validate_map(map);															// Check if map follows the rules required.
	initiate_flood(map);														// Checks accessibility of map elements from the player's position
}
