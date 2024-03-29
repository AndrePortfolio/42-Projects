/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/19 00:16:16 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	id;
	pid_t	id2;
	int		status;
	int		fd[2];

	if (argc != 5)
		error_message("Invalid number of arguments", NULL, 1);
	status = 0;
	if (pipe(fd) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	id = fork();
	if (id == 0)
		child_start_process(fd, argv, envp);
	id2 = fork();
	if (id2 == 0)
		child_end_process(fd, argv, envp);
	close_fds(fd, 0);
	waitpid(id, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}
