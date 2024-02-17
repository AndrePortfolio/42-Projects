/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:51:56 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/17 17:07:01 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map map)
{
	int i = 0;
	int j;;

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
}

int	main(int argc, char **argv)
{
	t_map	map;

	read_input(&map, argc, argv);


	print_map(map);
	// free_map(&map, NULL, 0);
}
