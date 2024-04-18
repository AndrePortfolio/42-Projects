/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:53:19 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 18:14:34 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*temp;

	i = 0;
	temp = s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((void *)&temp[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[] = "Hello World!";
	int i;

	i = 0;
	printf("My Function: %s\n", (char*)ft_memchr(str, 'a', 11));
	printf("Function:    %s\n", (char*)memchr(str, 'a', 11));
	return (0);
} */
