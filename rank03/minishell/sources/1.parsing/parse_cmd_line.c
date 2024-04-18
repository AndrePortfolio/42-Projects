/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:03:10 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 15:33:37 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree_node	*parse_cmd(t_tokens *t_start, t_tokens *t_end, t_shell *shell)
{
	t_tree_node	*cmd_node;
	t_tokens	*current;

	current = t_start;
	cmd_node = add_ast_node();
	while (current != t_end)
	{
		if (current->type >= RE_INPUT && current->type <= HEREDOC)
		{
			add_redir_list(&(cmd_node->redir_list),
				current->type, current->next->value);
			current = current->next;
		}
		else if (cmd_node->type == PHANTOM)
			ft_cmd_node(cmd_node, current, shell);
		else
			add_arg(&(cmd_node->args), current);
		current = current->next;
	}
	return (cmd_node);
}

t_tree_node	*parse_commandline(t_tokens *tokens_start, t_shell *shell)
{
	t_tree_node	*ast_head;
	t_tokens	*current;

	current = tokens_start;
	while (current && current->next)
	{
		if (current->type == PIPE)
		{
			ast_head = add_ast_node();
			ast_head->type = PIPE_TREE;
			ast_head->right = parse_commandline(current->next, shell);
			ast_head->left = parse_cmd(tokens_start, current, shell);
			return (ast_head);
		}
		current = current->next;
	}
	ast_head = parse_cmd(tokens_start, current->next, shell);
	return (ast_head);
}
