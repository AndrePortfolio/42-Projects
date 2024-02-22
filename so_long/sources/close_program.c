/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 01:26:28 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game, int status, int exit)
{
	mlx_destroy_image(game->mlx, game->map->wall.img);
	mlx_destroy_image(game->mlx, game->map->collectible.img);
	mlx_destroy_image(game->mlx, game->map->player.img);
	mlx_destroy_image(game->mlx, game->map->space.img);
	mlx_destroy_image(game->mlx, game->map->exit.img);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (exit == WON)
		free_map(game->map, "\nYou Won!", status);
	else
		free_map(game->map, "\nGame Over!", status);
	return (0);
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
	{
		ft_printf("%s\n", str);
		exit (0);
	}
}

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

