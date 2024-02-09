/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:35:24 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 10:20:13 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_map(t_map *map)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (map->map[ctd])
	{
		ctd2 = 0;
		while (map->map[ctd][ctd2])
		{
			ft_printf("%c", map->map[ctd][ctd2]);
			ctd2++;
		}
		ft_printf("\n");
		ctd++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	read_input(argc, argv, &map);	// Validates input parameters, reads map data from a .ber file, ensures map validity, and player access
	mlx_start(&map);				// 
	freemap(&map, NULL, 0);			// Frees memory
	return (0);
}
