/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/11 00:13:13 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_input(int argc, char **envp)
{
	if (argc < 5)
		error_message("Invalid number of arguments", NULL);
	if (envp[0] == NULL)
		error_message("No environmental variables", NULL);
}

void	error_message(char *str, char *cmd)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
	exit (1);
}

void	free_and_close(int fd, char **paths, char *path, char *path_cmd)
{
	if (!path_cmd)
	{
		if (path)
			free(path);
		close(fd);
		ft_freematrix(paths);
	}
	else
	{
		free(path);
		free(path_cmd);
	}
}

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
