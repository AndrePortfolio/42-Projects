/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:48 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/10 13:36:54 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc > 6)
		return (0);
	printf("%s %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4], argv[5]);
	ft_printf("%s %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4], argv[5]);
}
