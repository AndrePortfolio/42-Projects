/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:12:53 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:45:16 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_tokens(t_tokens *tokens)
{
	t_tokens	*current;

	if (!tokens)
		return (false);
	current = tokens;
	while (current)
	{
		if (current->type >= RE_INPUT && current->type <= HEREDOC)
		{
			if (!current->next)
				return (error_message("syntax error near `\\n'", NULL), true);
			else if (current->next->type == PIPE)
				return (error_message("syntax error near `|'", NULL), true);
			else if (current->next->type == RE_INPUT)
				return (error_message("syntax error near `<'", NULL), true);
			else if (current->next->type == RE_OUTPUT)
				return (error_message("syntax error near `>'", NULL), true);
			else if (current->next->type == APPEND)
				return (error_message("syntax error near `>>'", NULL), true);
			else if (current->next->type == HEREDOC)
				return (error_message("syntax error near `<<'", NULL), true);
		}
		current = current->next;
	}
	return (false);
}

void	pre_parse_tokens(t_tokens *tokens)
{
	t_tokens	*current;

	if (!tokens)
		return ;
	current = tokens;
	while (current && current->next)
	{
		if (current->type == RE_INPUT && current->next->type == RE_INPUT)
		{
			current->type = HEREDOC;
			del_token(&tokens, current->next);
		}
		else if (current->type == RE_OUTPUT && current->next->type == RE_OUTPUT)
		{
			current->type = APPEND;
			del_token(&tokens, current->next);
		}
		current = current->next;
	}
}

char	*trim_line(char *line, char *set)
{
	char	*str;
	int		len;

	str = ft_strtrim(line, set);
	len = ft_strlen(str);
	if (len >= 2 && ((str[len - 1] == '\"' && str[len - 2] == '\"')
			|| (str[len - 1] == '\'' && str[len - 2] == '\'')))
	{
		ft_bzero(&str[len - 2], 2);
	}
	return (str);
}

void	count_pipes(t_shell *shell)
{
	t_tokens	*current;

	current = shell->tokens;
	while (current != NULL)
	{
		if (current->type == PIPE)
			shell->pipe_nbr++;
		current = current->next;
	}
}
