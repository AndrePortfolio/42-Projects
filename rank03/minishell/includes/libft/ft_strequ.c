/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:50:23 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/01 16:51:14 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 != '=')
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if ((*s1 == '=' && *s2 == '\0') || (*s1 == '\0' && *s2 == '\0'))
		return (1);
	return (0);
}
// int main(void)
// {
// 	char *s1 = "PWD=/dhdhwdjwd";
// 	char *s2 = "PWD";

// 	printf("%d", ft_strequ(s1, s2));
// }
