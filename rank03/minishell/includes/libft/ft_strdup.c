/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:35:09 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/01 11:09:10 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		((unsigned char *)dup)[i] = ((unsigned char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	str[] = "Hello World!";
// 	char	*dup = ft_strdup(str);

// 	printf("My function: %s\n", dup);
// 	printf("Function:    %s\n", strdup(str));
// 	free(dup);
// 	return (0);
// }
