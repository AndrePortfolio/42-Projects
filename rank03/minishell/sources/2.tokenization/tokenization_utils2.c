/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:14:42 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:20:26 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*token_init(void)
{
	t_tokens	*new;

	new = (t_tokens *)malloc(sizeof(t_tokens));
	if (!new)
		return (error_message("malloc error: token init", NULL), NULL);
	new->previous = NULL;
	new->next = NULL;
	new->value = NULL;
	new->type = 0;
	new->space = 0;
	return (new);
}

int	args_len(t_args *args)
{
	int	len;

	len = 0;
	if (!args)
		return (len);
	while (args)
	{
		args = args->next;
		len++;
	}
	return (len);
}

void	del_token(t_tokens **head, t_tokens *node)
{
	if (*head == NULL || node == NULL)
		return ;
	if (*head == node)
	{
		*head = node->next;
		if (*head)
			(*head)->previous = NULL;
		free(node->value);
		free(node);
		return ;
	}
	if (node->previous)
		node->previous->next = node->next;
	if (node->next)
		node->next->previous = node->previous;
	free(node->value);
	free(node);
}

char	*handle_single_quotes(char *start, t_tokens *token)
{
	char	*word;

	word = ft_strdup_delimiter_char(++start, '\'');
	if (!word)
		return (error_message("token error: '\0' input", NULL), NULL);
	token->value = word;
	token->type = WORD;
	start += ft_strlen(word) + 1;
	if (ft_strchr(WHITESPACE, *start))
		token->space = 1;
	return (start);
}

char	*handle_double_quotes(char *start, t_tokens *token)
{
	char		*word;
	char		*dollar;

	word = ft_strdup_delimiter_char(++start, '\"');
	if (!word)
		return (error_message("token error: '\0' input", NULL), NULL);
	token->value = word;
	dollar = ft_strchr(word, '$');
	if (dollar && !ft_strchr(WHITESPACE, *(dollar + 1)))
		token->type = ENV_VAR;
	else
		token->type = WORD;
	start += ft_strlen(word) + 1;
	if (ft_strchr(WHITESPACE, *start))
		token->space = 1;
	return (start);
}
