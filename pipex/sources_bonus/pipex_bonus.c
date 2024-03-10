/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/10 20:39:13 by andrealbuqu      ###   ########.fr       */
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
	if (id == 0)
		child_start_process(fd[1], argv, envp);
	else
	{
		wait(NULL);
		id = fork();
		if (id == 0 && argc > 5)
			child_next_process(fd, argc, argv, envp);
		else if (id == 0)
			child_end_process(fd[1], argc, argv, envp);
		else
		{
			close(fd[0][READ_END]);
			close(fd[1][WRITE_END]);
			wait(NULL);
			id = fork();
			if (argc > 5)
			{
				if (id == 0)
					child_end_process(fd[1], argc, argv, envp);
				else
				{
					close(fd[1][READ_END]);
					close(fd[0][WRITE_END]);
				}
			}
		}
	}
	return (0);
}