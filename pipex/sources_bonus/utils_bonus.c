/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/13 19:43:12 by andre-da         ###   ########.fr       */
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
	use->cmd_nbr = argc - 3;
	use->id = malloc(sizeof(pid_t) * use->cmd_nbr);
	if (!(use->id))
		error_message("Memory allocation failed", NULL, 1);
	use->fd = malloc(sizeof(int *) * (use->cmd_nbr - 1));
	if (!(use->fd))
		error_message("Memory allocation failed", NULL, 1);
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

	i = -1;
	while (++i < use->cmd_nbr - 1)
	{
		if (i == child_num)  					// if this is the child
		{
			if (child_num != use->cmd_nbr - 1)	// if this is not the last child close read end
				close(use->fd[i][0]);
			else								// if this is the last child close write end
				close(use->fd[i][1]);
		}
		else if (i == child_num - 1)		// if this is the previous child, close write end
			close(use->fd[i][1]);				// because I want to read from that child
		else						// If no connection to that child, close both
		{
			close(use->fd[i][0]);
			close(use->fd[i][1]);
		}
	}
}