/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:13:55 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:16:40 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup_delimiter_char(const char *s, char delimiter)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] && s[i] != delimiter)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != delimiter)
	{
		((unsigned char *)dup)[i] = ((unsigned char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup_delimiter_string(const char *s, char *delimiter)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] && !ft_strchr(delimiter, s[i]))
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] && !ft_strchr(delimiter, s[i]))
	{
		((unsigned char *)dup)[i] = ((unsigned char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup_while_string(const char *s, char *delimiter)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] && ft_strchr(delimiter, s[i]))
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] && ft_strchr(delimiter, s[i]))
	{
		((unsigned char *)dup)[i] = ((unsigned char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*skip_whitespace(char *line)
{
	while (ft_strchr(WHITESPACE, *line) && *line)
		line++;
	return (line);
}

t_tokens	*add_node_back(t_tokens *previous)
{
	t_tokens	*new;

	new = (t_tokens *)malloc(sizeof(t_tokens));
	if (!new)
		return (error_message("malloc error: add token", NULL), NULL);
	new->previous = previous;
	new->next = NULL;
	previous->next = new;
	new->value = NULL;
	new->type = 0;
	new->space = 0;
	return (new);
}
