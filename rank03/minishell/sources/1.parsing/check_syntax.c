/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:40 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 12:50:25 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_quotation_marks(char *line)
{
	while (*line)
	{
		if (*line == '\"')
		{
			line = ft_strchr(line + 1, '\"');
			if (!line)
				return (error_message("parse error: unclosed quote", NULL),
					true);
		}
		else if (*line == '\'')
		{
			line = ft_strchr(line + 1, '\'');
			if (!line)
				return (error_message("parse error: unclosed quote", NULL),
					true);
		}
		line++;
	}
	return (false);
}

bool	check_pipes(char *line)
{
	char	*first_pipe;

	first_pipe = ft_strchr(line, '|');
	if (!first_pipe)
		return (false);
	first_pipe++;
	while (*first_pipe == ' ')
		first_pipe++;
	if (*first_pipe == '|')
		return (error_message("parse error: near `||'", NULL), true);
	if (ft_strncmp(line, "|", 1) == 0 || line[ft_strlen(line) - 1] == '|')
		return (error_message("parse error: near `|'", NULL), true);
	return (false);
}

bool	check_redirection(char *line)
{
	while (*line)
	{
		if (*line == '\'')
		{
			line++;
			while (*line && *line != '\'')
				line++;
		}
		if (*line == '\"')
		{
			line++;
			while (*line && *line != '\"')
				line++;
		}
		if (ft_strncmp(line, "<>", 2) == 0)
			return (error_message("parse error: near `>'", NULL), true);
		if (ft_strncmp(line, "><", 2) == 0)
			return (error_message("parse error: near `<'", NULL), true);
		line++;
	}
	return (false);
}

bool	check_syntax_errors(char *line)
{
	if (check_quotation_marks(line))
		return (true);
	if (check_pipes(line))
		return (true);
	if (check_redirection(line))
		return (true);
	return (false);
}
