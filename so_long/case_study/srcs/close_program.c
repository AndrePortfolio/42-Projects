/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:42:08 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/08 20:13:33 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);			// write str with \n at the end to stderr
	exit(1);						// quit the program due to error.
}

void	freemap(t_map *map, char *str, int status)
{
	int	ctd;

	ctd = 0;
	while (map->map[ctd])			// free each row from map (array)
		free(map->map[ctd++]);
	free(map->map);					// free map itself (array of arrays)
	if (status == 1)
		error_message(str);			// Display that it is being freeing due to an error
	else							// No error, simply end of program.
		exit(0);
}
