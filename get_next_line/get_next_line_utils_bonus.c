/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:27:52 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/24 17:43:09 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(int *nl_finder, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (!*nl_finder)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			*nl_finder = 0;
		buffer[i++] = '\0';
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		tlenght;
	char	*n_str;

	i = 0;
	j = 0;
	tlenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	n_str = (char *)malloc(sizeof(char) * tlenght);
	if (!n_str)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		n_str[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	n_str[i + j] = '\0';
	free(s1);
	return (n_str);
}
