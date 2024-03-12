/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/12 03:14:08 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	info_t	use;
	int		status;
	int		n;

	read_input(argc, envp, &use);
	status = 0;
	n = 3;
	if (pipe(use.fd[0]) == -1 || pipe(use.fd[1]) == -1)
		error_message("Failed to create the pipe(s)", NULL, 1);
	use.id[0] = fork();
	if (use.id[0] == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (use.id[0] == 0)
		child_start_process(use.fd, argv, envp);
	parent_process(argv, envp, &use);

	// fprintf(stderr, "use.id[0]: %d\n", use.id[0]);
	// fprintf(stderr, "use.id[1]: %d\n", use.id[1]);
	// fprintf(stderr, "use.id[2]: %d\n", use.id[2]);
	waitpid(use.id[0], NULL, 0);
	waitpid(use.id[1], NULL, 0);
	waitpid(use.id[2], &status, 0);
	while (argc - 5 > 0)
	{
		waitpid(use.id[n++], NULL, 0);
		argc--;
	}
	close_fds(use.fd);
	return (WEXITSTATUS(status));
}
