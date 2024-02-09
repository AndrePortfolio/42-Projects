/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:20:18 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 11:55:49 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	packman_init(t_mlx_start *par)
{
	par->packman = malloc(sizeof(t_packman));									// Allocates memory for packman
	if (par->packman == NULL)
		error_message("Error\nMalloc failed\n");								// Protects malloc
	find_start(par);															// Finds where packman (player) is
	par->packman->dir = 's';													// Initializes direction to "still"
	par->packman->next = 's';													// Initializes direction to "still"
	par->packman->prev = 's';													// Initializes direction to "still"
	par->packman->moves = 0;													// Initliaizes moves to 0
	par->packman->img[0].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_0.xpm", &par->packman->img[0].width,
			&par->packman->img[0].height);
	get_addr(par);
}
