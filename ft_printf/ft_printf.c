/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:54 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/25 17:57:47 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
			i = ft_format(format, args, i, ++j);
		else
		{
			write(1, &format[j], 1);
			i++;
		}
		j++;
	}
	va_end(args);
	return (i);
}

static int	ft_format(const char *format, va_list args, int i, int j)
{
	if (format[j] == 'c')
		i = ft_print_char(va_arg(args, int), i);
	if (format[j] == 's')
		i = ft_print_string(va_arg(args, char *), i);
	if (format[j] == 'd' || format[j] == 'i')
		i = ft_print_number(va_arg(args, int), i);
	if (format[j] == 'u')
		i = ft_print_unumber(va_arg(args, unsigned int), i);
	if (format[j] == 'x')
		i = ft_print_hexnumber(va_arg(args, int), i, 'x');
	if (format[j] == 'X')
		i = ft_print_hexnumber(va_arg(args, int), i, 'X');
	/* if (format[j] == 'p')
		i = ft_print_address(va_arg(args, void *), i); */
	if (format[j] == '%')
	{
		write(1, &format[j], 1);
		i++;
	}
	return (i);
}

static int	ft_print_char(int c, int i)
{
	write(1, &c, 1);
	i++;
	return (i);
}

static int	ft_print_string(char	*str, int i)
{
	if (!str)
		i = ft_print_string("(null)", i);
	else
	{
		while (*str)
		{
			write(1, &(*str), 1);
			i++;
			str++;
		}
	}
	return (i);
}

static int	ft_print_number(int nbr, int i)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		i += 11;
	}
	else if (nbr < 0)
	{
		i = ft_print_char('-', i);
		i = ft_print_number(-nbr, i);
	}
	else if (nbr >= 0 && nbr < 10)
	{
		i = ft_print_char(nbr + '0', i);
	}
	else
	{
		i = ft_print_number(nbr / 10, i);
		i = ft_print_char((nbr % 10) + '0', i);
	}
	return (i);
}

static int	ft_print_unumber(int nbr, int i)
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

static int	ft_print_hexnumber(int nbr, int i, char c)
{
	unsigned int	x;

	x = nbr;
	if (x == 0)
		i = ft_print_char('0', i);
	else if (x >= 16)
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

/* static int	ft_print_address(void	*address, int i)
{

} */

/* int	main(void)
{
	char	block1[] = "Hello my name is";
	char	block2[] = "and I am";
	char	block3[] = "years old!";
	char	name[] = "ndré";
	int		age = 23;
	char	c = 'A';

	printf("%s %c%s %s %d %s\n", block1, c, name, block2, age, block3);
	ft_printf("%s %c%s %s %d %s\n", block1, c, name, block2, age, block3);
} */
