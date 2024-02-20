/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/19 15:13:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	free_map(t_map *map, char *str, int status)
{
	int	row;

	row = 0;
	while (map->map[row])
		free(map->map[row++]);
	free(map->map);
	if (status)
		error_message(str);
	else
		exit (0);
}