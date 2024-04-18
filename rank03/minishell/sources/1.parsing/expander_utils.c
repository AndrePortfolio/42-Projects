/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:50:43 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 12:50:44 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_shell(t_shell *s, char *str)
{
	int		i;
	int		var_len;

	i = 0;
	var_len = ft_strlen(str);
	while (s->envp[i])
	{
		if (ft_strncmp(s->envp[i], str, var_len) == 0)
		{
			if (s->envp[i][var_len] == '=')
				return (ft_strdup(ft_strchr(s->envp[i], '=') + 1));
		}
		i++;
	}
	return (NULL);
}

char	*get_env(t_shell *shell, char *str)
{
	char	*env_value;

	if (*str == '$')
		return ("$$");
	env_value = get_env_shell(shell, str);
	if (!env_value)
		env_value = ft_strdup("");
	return (env_value);
}

/* finds environemnt variable and returns address to its $
will return NULL if no envp found */
char	*find_env(char *str)
{
	while (*str)
	{
		if (*str == '$' && *(str + 1) && !ft_strchr(WHITESPACE, *(str + 1)))
			return (str);
		str++;
	}
	return (NULL);
}

/* mallocs the string from s until envp
return null if nothing in s before envp*/
char	*ft_strdup_until(char *s)
{
	int		i;
	int		len;
	char	*dup;
	char	*end;

	if (!s)
		return (NULL);
	end = find_env(s);
	if (end == NULL)
		return (s);
	len = end - s;
	if (len < 1)
		return (NULL);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dup)[i] = ((unsigned char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_strs(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
}
