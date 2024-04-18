/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:27:18 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 14:52:06 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	alloc_pipes(t_shell *shell)
{
	int	i;

	shell->fd = (int **)malloc(sizeof(int *) * (shell->pipe_nbr + 2));
	if (!(shell->fd))
		error_message("Fds Memory allocation failed", NULL);
	shell->fd[0] = (int *)malloc(sizeof(int) * 2);
	if (!(shell->fd[0]))
		error_message("Fds Memory allocation failed", NULL);
	if (pipe(shell->fd[0]) == -1)
		error_message("Failed to create the pipe", NULL);
	shell->fd[1] = (int *)malloc(sizeof(int) * 2);
	if (!(shell->fd[1]))
		error_message("Fds Memory allocation failed", NULL);
	if (pipe(shell->fd[1]) == -1)
		error_message("Failed to create the pipe", NULL);
	i = 2;
	while (shell->pipe_nbr + 1 > i)
	{
		shell->fd[i] = 0;
		i++;
	}
	shell->fd[i] = NULL;
}
