/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:57:16 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 18:14:53 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && size > (i + 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/* int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[] = "";

	size_t	result = ft_strlcpy(dest, src, 5);
	printf("Lenght: %zu\n", result);
	printf("String: %s\n", dest);
	return (0);
} */
