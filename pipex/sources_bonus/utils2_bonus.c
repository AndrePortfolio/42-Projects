/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:33:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/11 21:46:15 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_last_process(int (*fd)[2], char **argv, char **envp, int *status)
{
	int		argc;
	pid_t	id;

	argc = get_argc(argv);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (id == 0)
	{
		if (argc > 5)
		{
			close(fd[0][READ_END]);
			close(fd[0][WRITE_END]);
			child_end_process(fd[1], argv, envp);
		}
	}
	(void)status;
	waitpid(id, status, 0);
}

void	close_fds(int (*fd)[2], bool all)
{
	if (all)
	{
		close(fd[1][WRITE_END]);
		close(fd[1][READ_END]);
	}
	close(fd[0][READ_END]);
	close(fd[0][WRITE_END]);
}

int	get_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
