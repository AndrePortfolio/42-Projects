/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/25 00:57:53 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_game *game, int status, int quit)
{
	int	i;

	i = 0;
	while (i < 8)
		mlx_destroy_image(game->mlx, game->map->player.img[i++]);
	mlx_destroy_image(game->mlx, game->map->wall.img);
	mlx_destroy_image(game->mlx, game->map->collectible.img);
	mlx_destroy_image(game->mlx, game->map->space.img);
	mlx_destroy_image(game->mlx, game->map->exit.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->map->enemy.img[0]);
	mlx_destroy_image(game->mlx, game->map->enemy.img[1]);
	// mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->map->player.img);
	free(game->map->enemy.img);
	if (quit == WON)
		free_map(game->map, "You Won!", status);
	else
		free_map(game->map, "Game Over!", status);
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
