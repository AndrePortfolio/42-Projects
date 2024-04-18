/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:11:12 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 18:14:38 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		*end;

	i = 0;
	str = src;
	end = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		end[i] = str[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[1000] = "";

	printf("Function:    %s\n", (char*)memcpy(dest, src, 5));
	printf("My Function: %s\n", (char*)ft_memcpy(dest, src, 5));
	return (0);
} */
