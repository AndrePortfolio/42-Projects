/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/11 00:44:45 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	id;
	int	fd[2][2];

	read_input(argc, envp);
	if (pipe(fd[0]) == -1 || pipe(fd[1]) == -1)
		error_message("Failed to create the pipe(s)", NULL);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL);
	else if (id == 0)
		child_start_process(fd[1], argv, envp);
	else
	{
		waitpid(id, NULL, 0);
		parent_process(id, fd, argv, envp);
	}
	return (0);
}
