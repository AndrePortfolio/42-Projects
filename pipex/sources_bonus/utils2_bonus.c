/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:33:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/11 00:33:52 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_last_process(int (*fd)[2], char **argv, char **envp)
{
	int		argc;

	argc = get_argc(argv);
	if (argc > 5)
		child_end_process(fd[1], argv, envp);
}

void	close_fds(int (*fd)[2])
{
	close(fd[0][READ_END]);
	close(fd[1][WRITE_END]);
	close(fd[1][READ_END]);
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
