/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:19 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 13:32:36 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->fd)
	{
		while (shell->fd[i])
			free(shell->fd[i++]);
		free(shell->fd);
	}
	if (shell->id)
		free(shell->id);
	if (shell->id_exec)
		free(shell->id_exec);
	if (shell->tokens)
		free_tokens(shell->tokens);
	if (shell->tree)
		free_tree(shell->tree);
	if (shell->line)
		free(shell->line);
}

void	free_redir_list(t_redir_list *redir_list)
{
	t_redir_list	*current;
	t_redir_list	*temp;

	if (!redir_list)
		return ;
	current = redir_list;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	free_args(t_args *args)
{
	t_args	*current;
	t_args	*temp;

	if (!args)
		return ;
	current = args;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	free_tree(t_tree_node *node)
{
	if (!node)
		return ;
	if (node->left)
		free_tree(node->left);
	if (node->right)
		free_tree(node->right);
	if (node->redir_list)
		free_redir_list(node->redir_list);
	if (node->args)
		free_args(node->args);
	free(node);
}

void	free_tokens(t_tokens *head)
{
	t_tokens	*current;
	t_tokens	*next_node;

	if (!head)
		return ;
	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		if (current->value != NULL)
			free(current->value);
		free(current);
		current = next_node;
	}
}
