/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:34:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/12/13 13:41:54 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_p;
	unsigned char		*dest_p;

	i = 0;
	src_p = src;
	dest_p = dest;
	if (src_p < dest_p)
	{
		while (n > 0)
		{
			n--;
			dest_p[n] = src_p[n];
		}
	}
	else if (src_p > dest_p)
	{
		while (i < n)
		{
			dest_p[i] = src_p[i];
			i++;
		}
	}
	return (dest);
}

int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[1000] = "Hello";

	printf("My Function: %s\n", (char*)ft_memmove(dest, src, 13));
	printf("Function:    %s\n", (char*)memmove(dest, src, 13));
	return (0);
}
