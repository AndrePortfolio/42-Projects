/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:03:03 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 18:14:32 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("My Function: %d\n", ft_isprint('!'));
	printf("Function:    %d\n", isprint('!'));
	return (0);
} */
