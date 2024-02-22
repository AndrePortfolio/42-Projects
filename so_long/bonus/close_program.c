/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 17:15:29 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game, int status, int quit)
{
	int i;

	i = 0;
	while (i < 8)
		mlx_destroy_image(game->mlx, game->map->player.img[i++]);
	mlx_destroy_image(game->mlx, game->map->wall.img);
	mlx_destroy_image(game->mlx, game->map->collectible.img);
	mlx_destroy_image(game->mlx, game->map->space.img);
	mlx_destroy_image(game->mlx, game->map->exit.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->map->player.img);
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

