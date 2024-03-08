/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/08 22:59:29 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	id;
	int	fd[2];

	read_input(argc, envp);
	if (pipe(fd) == -1)
		error_message("Failed to create the pipe(s)", NULL);
	id = fork();
	if (id == 0)
		child_start_process(fd, argv, envp);
	else
	{
		id = fork();
		wait(NULL);
		if (id == 0)
			child_end_process(fd, argv, envp);
		else
		{
			close(fd[READ_END]);
			close(fd[WRITE_END]);
		}
	}
	return (0);
}
