/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:18:06 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/18 14:49:56 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_beg(char const *s1, char const *set);
static int	ft_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		lenght;
	int		i;
	int		beg;
	int		end;

	i = -1;
	beg = ft_beg(s1, set);
	if (beg >= (int)ft_strlen(s1))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	end = ft_end(s1, set);
	lenght = ft_strlen(s1) - (beg + end);
	str = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	while (++i < lenght)
		str[i] = s1[beg + i];
	str[i] = '\0';
	return (str);
}

static int	ft_beg(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		g;

	i = 0;
	j = ft_strlen(set);
	g = 0;
	while (s1[g] && j > i)
	{
		if (s1[g] == set[i])
		{
			g++;
			i = -1;
		}
		i++;
	}
	return (g);
}

static int	ft_end(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		g;

	i = 0;
	j = ft_strlen(set);
	g = ft_strlen(s1) - 1;
	while (g > 0 && j > i)
	{
		if (s1[g] == set[i])
		{
			g--;
			i = -1;
		}
		i++;
	}
	return (ft_strlen(s1) - 1 - g);
}

/* int	main(void)
{
	char	str[] = "llllo Worlhe";
	char	trim[] = "ehl";

	printf("%s\n", ft_strtrim(str, trim));
	return (0);
} */
