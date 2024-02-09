/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:06 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:44 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_memcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}
