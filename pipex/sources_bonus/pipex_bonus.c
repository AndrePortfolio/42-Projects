/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/11 20:10:30 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	id;
	int		fd[2][2];
	int		status;

	read_input(argc, envp);
	status = 0;
	if (pipe(fd[0]) == -1 || pipe(fd[1]) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (id == 0)
		child_start_process(fd[1], argv, envp);
	parent_process(fd, argv, envp, &status);
	waitpid(id, NULL, 0);
	return (WEXITSTATUS(status));
}
