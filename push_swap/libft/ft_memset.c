/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:13:29 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 18:56:04 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_p;

	s_p = s;
	i = 0;
	while (i < n)
	{
		s_p[i] = (const unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char str[20];

	printf("My Function: %s\n", (char *)ft_memset(str, 's', 20));
	printf("Function:    %s\n", (char *)memset(str, 's', 20));
	return (0);
} */
