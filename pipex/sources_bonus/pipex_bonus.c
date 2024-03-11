/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/11 18:13:11 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	id;
	int		fd[2][2];

	read_input(argc, envp);
	if (pipe(fd[0]) == -1 || pipe(fd[1]) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (id == 0)
		child_start_process(fd[1], argv, envp);
	else
		parent_process(id, fd, argv, envp);
	waitpid(id, NULL, 0);
	return (0);
}
