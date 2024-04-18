/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:10:17 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 15:44:53 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree_node	*add_ast_node(void)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (!new_node)
		return (error_message("malloc error: adding cmd node", NULL), NULL);
	new_node->type = PHANTOM;
	new_node->cmd = NULL;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->redir_list = NULL;
	new_node->args = NULL;
	new_node->builtin = NULL;
	return (new_node);
}

void	add_redir_list(t_redir_list **head, t_token_type type, char *file)
{
	t_redir_list	*new;
	t_redir_list	*current;

	current = NULL;
	new = (t_redir_list *)malloc(sizeof(t_redir_list));
	if (!new)
		return (error_message("malloc error redir list", NULL));
	if (!file)
		return (error_message("not a valid file", NULL));
	new->type = type;
	new->file = file;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

/* add arg to args */
void	add_arg(t_args **args, t_tokens *current)
{
	t_args	*new_arg;
	t_args	*cur_arg;

	cur_arg = NULL;
	new_arg = (t_args *)malloc(sizeof(t_args));
	if (!new_arg)
		return (error_message("malloc error args", NULL));
	new_arg->arg = current->value;
	new_arg->next = NULL;
	new_arg->space = current->space;
	if (!*args)
		*args = new_arg;
	else
	{
		cur_arg = *args;
		while (cur_arg->next)
			cur_arg = cur_arg->next;
		cur_arg->next = new_arg;
	}
}

void	ft_cmd_node(t_tree_node *cmd_node, t_tokens *current, t_shell *s)
{
	cmd_node->builtin = builtin_arr(current->value);
	if (cmd_node->builtin != NULL)
	{
		s->builtins++;
		cmd_node->type = BUILTIN;
	}
	else
	{
		cmd_node->type = CMD;
		cmd_node->cmd = current->value;
	}
}
