/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:43:25 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/14 17:20:07 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_map *map, int fd, int count)
{
	char *line;

	line = get_next_line(fd);
	if (line != NULL)
		read_map(map, fd, count++);
	else
	{
		if (count == 0)
			error_message("Empty map");
		map->map = malloc(sizeof(char *) * count + 1);
		if (map->map == NULL)
			error_message("Error allocating memory");
		map->rows = count;
	}
	if (line)
	{
		map->map[count] = ft_strtrim(line, "\n");
		free(line);
	}
	else
		map->map[count] = NULL;
}
