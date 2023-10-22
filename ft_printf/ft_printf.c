/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:54 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/22 19:25:28 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(int c);
static int	print_string(char	*str);
static int	print_address(void	*address, int base);
static int	print_number(int nbr, int base);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(ap, *format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += print_char(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'p')
				count += print_address(va_arg(ap, void *), 16);
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				count += print_number(va_arg(ap, int), 10);
			else if (format[i] == 'x' || format[i] == 'X')
				count += print_number(va_arg(ap, char *), 16);
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

static int print_char(int	c)
{
	write(1, &c, 1);
	return (1);
}

static int print_string(char	*str)
{

}

static int print_address(void	*address, int	base)
{

}

static int print_number(int nbr, int	base)
{

}

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
