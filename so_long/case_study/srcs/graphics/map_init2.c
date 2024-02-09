/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:13:24 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 22:19:59 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	map_init(t_mlx_start *par)
{
	wall_init(par);				// Initializes wall
	floor_init(par);			// Initializes floor
	exit_init(par);				// Initializes exit
	collectible_init(par);		// Initializes collectibles
	boarder_init(par);			// Initializes boarders
}
