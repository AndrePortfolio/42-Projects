/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/13 15:03:00 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_input(int argc, char **envp, t_info *use)
{
	int i;

	i = 0;
	if (argc < 5)
		error_message("Invalid number of arguments", NULL, 1);
	if (!envp)
		error_message("No environmental variables", NULL, 1);
	use->id = malloc(sizeof(pid_t) * (argc - 2));
	if (!use->id)
		error_message("Memory allocation failed", NULL, 1);
	use->cmd_nbr = argc - 3;
	use->fd = malloc(sizeof(int *) * (use->cmd_nbr - 1));
	if (!(use->fd))
		error_message("Memory allocation failed", NULL, 1);
	while (i < 2)
	{
		use->fd[i] = malloc(sizeof(int) * 2);
		if (!(use->fd[i]))
			error_message("Memory allocation failed", NULL, 1);
		if (pipe(use->fd[i]) == -1)
			error_message("Failed to create the pipe(s)", NULL, 1);
		i++;
	}
}

void	error_message(char *str, char *cmd, int code)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
	free(cmd);
	exit (code);
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

void	close_fds(int **fd)
{
	if (fd[0][WRITE_END] >= 0)
		close(fd[1][WRITE_END]);
	if (fd[0][READ_END] >= 0)
		close(fd[1][READ_END]);
	if (fd[1][WRITE_END] >= 0)
		close(fd[1][WRITE_END]);
	if (fd[1][READ_END] >= 0)
		close(fd[1][READ_END]);
}
