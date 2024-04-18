/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:18:35 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:45:27 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*token_word(char *start, t_tokens *token, char *delimiter)
{
	char	*word;

	word = ft_strdup_delimiter_string(start, delimiter);
	if (!word)
		return (error_message("token error: no word", NULL), NULL);
	token->value = word;
	token->type = WORD;
	start += ft_strlen(word);
	if (ft_strchr(WHITESPACE, *start))
		token->space = 1;
	return (start);
}

char	*token_dollar(char *start, t_tokens *token)
{
	char	*word;

	word = ft_strdup_delimiter_string(start, WHITESPACE);
	if (!word)
		return (error_message("token error: no word", NULL), NULL);
	token->value = word;
	token->type = WORD;
	start += ft_strlen(word);
	if (ft_strchr(WHITESPACE, *start))
		token->space = 1;
	return (start);
}

char	*single_token(char *start, t_tokens *token)
{
	if (*start == '<')
		token->type = RE_INPUT;
	else if (*start == '>')
		token->type = RE_OUTPUT;
	else if (*start == '|')
		token->type = PIPE;
	else
		return (error_message("token error: no single token", NULL), NULL);
	start++;
	return (start);
}

char	*token_envp(char *start, t_tokens *token)
{
	char	*word;

	if (*(start + 1) == '?')
		word = ft_strdup("$?");
	else if (*(start + 1) == '$')
		word = ft_strdup("$$");
	else
		word = ft_strdup_delimiter_string(start, WHITESPACE_QUOTES);
	if (!word)
		return (error_message("token error:", NULL), NULL);
	token->value = word;
	token->type = ENV_VAR;
	start += ft_strlen(word);
	if (ft_strchr(WHITESPACE, *start))
		token->space = 1;
	return (start);
}

void	remove_empty_tokens(t_tokens **tokens)
{
	t_tokens	*current;
	t_tokens	*temp;

	if (!tokens || !(*tokens))
		return ;
	current = *tokens;
	temp = NULL;
	while (current)
	{
		if (current->type == 6 && ft_strcmp("", current->value) == 0)
		{
			temp = current->next;
			del_token(tokens, current);
			current = temp;
		}
		else
			current = current->next;
	}
}
