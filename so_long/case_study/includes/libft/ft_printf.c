/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/09 20:48:01 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptraux(unsigned long int ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		len += ft_putstr_fd("(nil)", 1);
	else
	{
		len += write(1, "0x", 2);
		len += ft_putpt(ptr, EX_LOW_BASE, 0);
	}
	return (len);
}

int	straux(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	else
		return (ft_putstr_fd(str, 1));
}

int	flag_type(char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd((va_arg(*args, int)), 1);
	if (c == 's')
		len += straux(va_arg(*args, char *));
	if (c == 'p')
	{
		len += ptraux(va_arg(*args, long int));
	}
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*args, int), 0);
	if (c == 'u')
		len += ft_putunbr(va_arg(*args, unsigned int), 0);
	if (c == 'x')
		len += ft_putnbr_base(va_arg(*args, long int), EX_LOW_BASE, 0);
	if (c == 'X')
		len += ft_putnbr_base(va_arg(*args, long int), EX_UP_BASE, 0);
	if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

static int	is_char(const char *str, const char c)
{
	int	ctd;

	ctd = 0;
	while (str[ctd])
	{
		if (str[ctd] == c)
			return (1);
		ctd++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		ctd;
	va_list	args;

	if (!str)
		return (-1);
	ctd = 0;
	len = 0;
	va_start(args, str);
	while (str[ctd])
	{
		if (str[ctd] == '%' && is_char(PRINTF_FLAGS, str[ctd + 1]))
		{
			ctd++;
			len += flag_type(str[ctd], &args);
		}
		else
			len += write(1, &str[ctd], 1);
		ctd++;
	}
	va_end(args);
	return (len);
}
