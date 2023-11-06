/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/06 15:57:05 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unumber(int nbr, int i)
{
	unsigned int	nb;

	nb = nbr;
	if (nb >= 0 && nb < 10)
		i = ft_print_char(nb + '0', i);
	else
	{
		i = ft_print_number(nb / 10, i);
		i = ft_print_char((nb % 10) + '0', i);
	}
	return (i);
}

int	ft_print_hexnumber(int nbr, int i, char c)
{
	unsigned int	x;

	x = nbr;
	if (x >= 16)
	{
		i = ft_print_hexnumber(x / 16, i, c);
		i = ft_print_hexnumber(x % 16, i, c);
	}
	else
	{
		if (x <= 9)
			i = ft_print_char(x + '0', i);
		else if (c == 'x')
			i = ft_print_char(x + 'a' - 10, i);
		else
			i = ft_print_char(x + 'A' - 10, i);
	}
	return (i);
}

int	ft_print_hex_pnumber(long nbr, int i)
{
	unsigned long	x;

	x = nbr;
	if (x >= 16)
	{
		i = ft_print_hex_pnumber(x / 16, i);
		i = ft_print_hex_pnumber(x % 16, i);
	}
	else
	{
		if (x <= 9)
			i = ft_print_char(x + '0', i);
		else
			i = ft_print_char(x + 'a' - 10, i);
	}
	return (i);
}

int	ft_print_address(void	*address, int i)
{
	if (address == NULL)
	{
		i = ft_print_string("0x0", i);
		return (i);
	}
	else
	{
		write(1, "0x", 2);
		i = ft_print_hex_pnumber((long)(uintptr_t)address, i);
		return (i + 2);
	}
}
