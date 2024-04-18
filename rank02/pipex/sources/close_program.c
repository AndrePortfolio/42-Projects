/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:39:03 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/18 22:30:49 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_error_message(char *str, char *cmd, int code, int *fd)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
	close_fds(fd, 0);
	exit (code);
}

void	error_message(char *str, char *cmd, int code)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
	exit (code);
}

void	free_and_close(int fd, char **paths, char *path, char *path_cmd)
{
	if (!path_cmd)
	{
		if (path)
			free(path);
		if (fd >= 0)
			close(fd);
		ft_freematrix(paths);
	}
	else
	{
		free(path);
		free(path_cmd);
	}
}

void	close_fds(int *fd, int file)
{
	if (fd[READ_END] >= 0)
		close(fd[READ_END]);
	if (fd[WRITE_END] >= 0)
		close(fd[WRITE_END]);
	if (file >= 0)
		close(file);
}
