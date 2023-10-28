/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/28 16:29:03 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_format(const char *format, va_list args, int i, int j);
int	ft_print_char(int c, int i);
int	ft_print_string(char *str, int i);
int	ft_print_number(int nbr, int i);
int	ft_print_unumber(int nbr, int i);
int	ft_print_hexnumber(int nbr, int i, char c);
int	ft_print_hex_pnumber(long nbr, int i);
int	ft_print_address(void	*address, int i);

#endif
