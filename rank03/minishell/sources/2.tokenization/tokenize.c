/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:23:27 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:57:49 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* concetonates all tokens if there is no space between them */
void	remove_spaces(t_tokens **tokens)
{
	t_tokens	*current;
	int			flag;

	if (!tokens || !(*tokens))
		return ;
	current = *tokens;
	flag = 0;
	while (current && current->next)
	{
		while ((current->type == 5 || current->type == 6)
			&& (current->next->type == 5 || current->next->type == 6)
			&& current->space == 0)
		{
			flag = 0;
			current->value = ft_strjoin_free(current->value,
					current->next->value);
			if (current->next->space == 1)
				flag = 1;
			del_token(tokens, current->next);
			if (!current->next || flag == 1)
				break ;
		}
		current = current->next;
	}
}

t_tokens	*tokenize(t_shell *shell)
{
	char		*trimmed_line;

	trimmed_line = trim_line(shell->line, WHITESPACE);
	if (!trimmed_line)
		return (NULL);
	if (check_syntax_errors(trimmed_line))
	{
		shell->status = 2;
		return (NULL);
	}
	shell->tokens = get_tokens(trimmed_line);
	pre_parse_tokens(shell->tokens);
	free(trimmed_line);
	count_pipes(shell);
	return (shell->tokens);
}

char	*handle_line(char *l, t_tokens *current)
{
	char	*line;

	line = l;
	if (*line == '\'')
		line = handle_single_quotes(line, current);
	else if (*line == '\"')
		line = handle_double_quotes(line, current);
	else if (ft_strchr(SINGLE_TOKENS, *line))
		line = single_token(line, current);
	else if (*line == '$' && ft_strchr(WHITESPACE, *(line + 1)))
		line = token_dollar(line, current);
	else if (*line == '$' && !ft_strchr(WHITESPACE, *(line + 1)))
		line = token_envp(line, current);
	else if (*line == '?')
		line = token_word(line, current, WHITESPACE_Q_D_N);
	else
		line = token_word(line, current, WHITESPACE_Q_D);
	return (line);
}

t_tokens	*get_tokens(char *line)
{
	t_tokens	*head;
	t_tokens	*current;
	t_tokens	*previous;

	head = token_init();
	current = head;
	previous = NULL;
	if (!line || *line == '\0')
		return (free(current), NULL);
	while (*line != '\0')
	{
		line = skip_whitespace(line);
		if (!line || *line == '\0')
			break ;
		line = handle_line(line, current);
		previous = current;
		current = add_node_back(previous);
	}
	free(current);
	previous->next = NULL;
	return (head);
}
