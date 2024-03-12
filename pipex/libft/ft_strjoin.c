/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:06:55 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/12 19:34:22 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		tlenght;
	char	*n_str;

	i = 0;
	j = 0;
	tlenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	n_str = (char *)malloc(sizeof(char) * tlenght);
	if (n_str == NULL)
		return (NULL);
	while (s1[i])
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		n_str[i + j] = s2[j];
		j++;
	}
	n_str[i + j] = '\0';
	return (n_str);
}

/* int	main(void)
{
	char	*string1 = "Hello";
	char	*string2 = " World!";
	char	*string3;

	string3 = ft_strjoin(string1, string2);
	printf("%s\n", string3);
	free (string3);
	return (0);
} */
