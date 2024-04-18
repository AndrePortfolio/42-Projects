/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:19 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:00:20 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_env(t_shell *shell, t_tree_node *tree)
{
	int	i;

	i = 0;
	if (tree->args != NULL)
		return (EXIT_FAILURE);
	while (shell->envp[i])
	{
		ft_putendl_fd(shell->envp[i], STDOUT_FILENO);
		i++;
	}
	(void)tree;
	return (EXIT_SUCCESS);
}
