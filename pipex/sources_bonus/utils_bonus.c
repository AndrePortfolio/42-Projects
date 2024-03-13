/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/13 22:32:31 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_input(int argc, char **envp, t_info *use)
{
	int i;

	if (argc < 5)
		error_message("Invalid number of arguments", NULL, 1);
	if (!envp)
		error_message("No environmental variables", NULL, 1);
	use->cmd_nbr = argc - 3;
	use->id = malloc(sizeof(pid_t) * use->cmd_nbr);
	if (!(use->id))
		error_message("Memory allocation failed", NULL, 1);
	use->fd = malloc(sizeof(int *) * (use->cmd_nbr - 1));
	if (!(use->fd))
		error_message("Memory allocation failed", NULL, 1);
	i = 0;
	while (i < use->cmd_nbr - 1)
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

void	close_all_fds(t_info *use)
{
	int	pipes;
	int	i;

	i = 0;
	pipes = use->cmd_nbr - 1;
	while (i < pipes)
	{
		if (use->fd[i][WRITE_END] >= 0)
			close(use->fd[i][WRITE_END]);
		if (use->fd[i][READ_END] >= 0)
			close(use->fd[i][READ_END]);
		i++;
	}
}

void	close_unused_fds(t_info *use, int child_num)
{
	int	i;

	i = 0;
	while (i < use->cmd_nbr - 1)
	{
		if (i == child_num)
		{
			if (child_num != use->cmd_nbr - 1)
				close(use->fd[i][0]);
			else
				close(use->fd[i][1]);
		}
		else if (i == child_num - 1)
			close(use->fd[i][1]);
		else
		{
			close(use->fd[i][0]);
			close(use->fd[i][1]);
		}
		i++;
	}
}
