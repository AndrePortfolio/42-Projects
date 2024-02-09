/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:20:25 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 22:57:09 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));	// Extracts from the address the color of the pixel
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));	// Extracts from the address the color of the pixel
	return (*(unsigned int *)dst);												// Return the color.
}

int	put_screen(t_mlx_start *par, t_img *img)
{
	mlx_clear_window(par->mlx, par->mlx_win);
	mlx_put_image_to_window(par->mlx, par->mlx_win, img->img, 0, 0);
	return (0);
}

void	create_img(t_img *img, t_img src, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < src.width)								// Iterate through the the width
	{
		j = 0;
		while (j < src.height)							// Iterate through the the height
		{
			color = get_pixel(&src, i, j);				// Extracts from the color of the pixel
			if (color != TRANSPARENT)					// If the pixel is any collor but transparent
				put_pixel(img, x + i, y + j, color);	// Put this pixel in the image
			j++;
		}
		i++;
	}
}

void	initialize_image(t_mlx_start *par, t_img *img, int width, int height)
{
	img->img = mlx_new_image(par->mlx, width, height);				// Sets Image to fill the whole window
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,	// Gets the address of img, bits_pp, line_lenght & endian
			&img->line_length, &img->endian);
	par->load_img = img;											// Sets par-load_img to img which was initialized already
}
