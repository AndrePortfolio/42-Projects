/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:13:40 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/16 20:18:42 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{
	char	character = 'A';
	int		file_descriptor = 1;

	ft_putchar_fd(character, file_descriptor);
	write(1, "\n", 1);
	return (0);
} */
