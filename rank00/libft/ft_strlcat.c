/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:59:11 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 18:14:50 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if ((size - 1) > i && size > 0)
	{
		while (src[j] && size > (i + j + 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	if (size < i)
		return (j + size);
	return (i + j);
}

/* int	main(void)
{
	char	src[] = " World!";
	char	dest[14] = '"Hello"';

	size_t result = ft_strlcat(dest, src, sizeof(dest));
    printf("Lenght: %zu\n", result);
	printf("String: %s\n", dest);
	return (0);
} */
