/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/25 17:58:55 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *, ...);
static int	ft_format(const char *format, va_list args, int i, int j);
static int	ft_print_char(int c, int i);
static int	ft_print_string(char *str, int i);
static int	ft_print_number(int nbr, int i);
static int	ft_print_unumber(int nbr, int i);
static int	ft_print_hexnumber(int nbr, int i, char c);
// static int	ft_print_address(void	*address, int i);

#endif
