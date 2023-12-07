/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:13:00 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 19:20:27 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	str[] = "";

	printf("My function: %s\n", (char *)ft_calloc(ft_strlen(str), sizeof(str)));
	printf("Function:    %s\n", (char *)calloc(ft_strlen(str), sizeof(str)));
	return (0);
} */
