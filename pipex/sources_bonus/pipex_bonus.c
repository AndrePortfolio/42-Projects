/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/12 20:49:08 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	wait_pids(int argc, t_info *use)
{
	int	status;
	int	i;

	i = 0;
	while (argc - 4 > 0)
	{
		waitpid(use->id[i++], NULL, 0);
		argc--;
	}
	waitpid(use->id[i], &status, 0);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	use;
	int		status;

	read_input(argc, envp, &use);
	if (pipe(use.fd[0]) == -1 || pipe(use.fd[1]) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	start_processes(argc, argv, envp, &use);
	status = wait_pids(argc, &use);
	close_fds(use.fd);
	free(use.id);
	return (WEXITSTATUS(status));
}
