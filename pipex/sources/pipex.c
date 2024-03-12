/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/12 18:16:24 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	id;
	pid_t	id2;
	int		status;
	int		fd[2];

	read_input(argc, envp);
	status = 0;
	if (pipe(fd) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	id = fork();
	if (id == 0)
		child_start_process(fd, argv, envp);
	id2 = fork();
	if (id2 == 0)
		child_end_process(fd, argv, envp);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(id, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}