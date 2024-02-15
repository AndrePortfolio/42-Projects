/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:50:02 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/14 16:46:01 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_input(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		error_message("Invalid number of arguments");
	int	name;

	name = ft_strlen(argv[1]) - 4;
	if (name <= 0 || ft_strncmp(argv[1] + name, ".ber", 4) != 0)
		error_message("Invalid file, must be a .ber file");
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Error opening file");
	read_map(map, fd);
	close(fd);
	validate(map);
}
