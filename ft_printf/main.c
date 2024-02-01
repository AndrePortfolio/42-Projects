/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:48 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/01 12:27:59 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	block1[] = "Hello my name is";
	char	block2[] = "and I am";
	char	block3[] = "years old!";
	char	name[] = "ndré";
	int		age = 23;
	char	c = 'A';

	printf("%s %c%s %s %d %s\n", block1, c, name, block2, age, block3);
	ft_printf("%s %c%s %s %d %s\n", block1, c, name, block2, age, block3);
}
