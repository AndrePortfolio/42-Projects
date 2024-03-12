/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:05 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	wait_pids(int argc, t_info *use)
{
	int	status;
	int	n;

	n = 3;
	waitpid(use->id[0], NULL, 0);
	waitpid(use->id[1], NULL, 0);
	waitpid(use->id[2], &status, 0);
	while (argc - 5 > 0)
	{
		waitpid(use->id[n++], NULL, 0);
		argc--;
	}
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	use;
	int		status;

	read_input(argc, envp, &use);
	if (pipe(use.fd[0]) == -1 || pipe(use.fd[1]) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	use.id[0] = fork();
	if (use.id[0] == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (use.id[0] == 0)
		child_start_process(use.fd, argv, envp);
	parent_process(argv, envp, &use);
	status = wait_pids(argc, &use);
	close_fds(use.fd);
	free(use.id);
	return (WEXITSTATUS(status));
}
