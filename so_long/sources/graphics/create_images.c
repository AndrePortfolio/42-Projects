/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:48:44 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/20 22:31:28 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	put_screen(t_game *game, t_img *img)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, img->img, 0, 0);
	return (0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_lenght + x * (img->bits_pp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->l_lenght + x * (img->bits_pp / 8));
	return (*(unsigned int *)dst);
}

void	create_image(t_img *img, t_img character, int width, int height)
{
	unsigned int	color;
	int				x;
	int				y;

	x = 0;
	ft_printf("src.width: %d\n", character.width);
	ft_printf("src.height: %d\n", character.height);
	ft_printf("img:        %p\n", character);
	while (x < character.width)
	{
		y = 0;
		while (y < character.height)
		{
			color = get_pixel(&character, x, y);
			//ft_printf("color: %d x: %d y: %d\n", color, x, y);
			if (color != TRANSPARENT)
				put_pixel(img, x + width, y + height, color);
			y++;
		}
		x++;
	}
}

void	create_game_images(t_game *game, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (game->map->map[x])
	{
		y = 0;
		while (game->map->map[x][y])
		{
			if (game->map->map[x][y] == WALL)
				create_image(img, game->map->wall, (x * SCALE) + BOARDER, (y * SCALE) + BOARDER);
			else if (game->map->map[x][y] == PLAYER)
				create_image(img, game->map->player, (x * SCALE) + BOARDER, (y * SCALE) + BOARDER);
			else if (game->map->map[x][y] == EMPTY)
				create_image(img, game->map->space, (x * SCALE) + BOARDER, (y * SCALE) + BOARDER);
			else if (game->map->map[x][y] == COLLECTIBLE)
				create_image(img, game->map->collectible, (x * SCALE) + BOARDER, (y * SCALE) + BOARDER);
			else if (game->map->map[x][y] == EXIT)
				create_image(img, game->map->exit, (x * SCALE) + BOARDER, (y * SCALE) + BOARDER);
			y++;
		}
		x++;
	}
}
