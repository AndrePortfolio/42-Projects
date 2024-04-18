/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:41:53 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/10 20:10:59 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] == s2[i]) && (n > i) && (s1[i] != '\0'))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int	main(void)
{
	char	str1[] = "abcdef";
	char	str2[] = "abc\375xx";

	printf("My Function: %d\n", ft_strncmp(str1, str2, 5));
	printf("Function:    %d\n", strncmp(str1, str2, 5));
	return (0);
} */
