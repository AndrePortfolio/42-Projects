/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 11:18:00 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	read_input(&map, argc, argv);
	mlx_start(&map);
	free_map(&map, "Game over", 0);
}

/* static void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			ft_printf("%c", map.map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
} */
