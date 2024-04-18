/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:50:59 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:00:32 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_and_replace(t_shell *shell, char *org_str)
{
	char		*str_before;
	char		*str_env;
	char		*result;
	char		*env;

	if (!org_str)
		return (NULL);
	result = ft_strdup("");
	while (*org_str)
	{
		str_before = ft_strdup_until(org_str);
		org_str = find_env(org_str);
		if (!org_str)
		{
			result = ft_strjoin_free(result, str_before);
			break ;
		}
		str_env = ft_strdup_while_string(++org_str, LETTERS_DIGITS);
		env = get_env(shell, str_env);
		str_before = ft_strjoin_free(str_before, env);
		org_str += ft_strlen(str_env);
		result = ft_strjoin_free(result, str_before);
		free_strs(str_before, str_env, env);
	}
	return (result);
}

void	expand_status(t_shell *shell, t_tokens *current)
{
	free(current->value);
	current->value = ft_itoa(shell->status);
}

/* expands environment variables in the token list,
replacing them by their value or by a empty string (\0\0) */
void	expand(t_shell *shell)
{
	t_tokens	*current;
	char		*temp;

	current = shell->tokens;
	temp = NULL;
	while (current)
	{
		if (current->type == 6)
		{
			if (current->previous && current->previous->type == HEREDOC)
			{
			}
			else if (!ft_strcmp(current->value, "$?"))
				expand_status(shell, current);
			else if (ft_strcmp(current->value, "$$"))
			{
				temp = current->value;
				current->value = find_and_replace(shell, temp);
				free(temp);
			}
		}
		current = current->next;
	}
}
