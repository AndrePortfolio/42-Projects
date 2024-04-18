/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:45:25 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/18 22:36:38 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	close_all_fds(t_info *use)
{
	int	pipes;
	int	i;

	i = 0;
	pipes = use->cmd_nbr - 1;
	if (use->infile >= 0)
		close(use->infile);
	if (use->outfile >= 0)
		close(use->outfile);
	while (i < pipes)
	{
		if (use->fd[i][WRITE_END] >= 0)
			close(use->fd[i][WRITE_END]);
		if (use->fd[i][READ_END] >= 0)
			close(use->fd[i][READ_END]);
		i++;
	}
	if (use->here_doc)
		unlink("here_doc");
}

void	free_all(t_info *use)
{
	int	i;

	i = 0;
	while (use->fd[i])
		free(use->fd[i++]);
	if (use->fd)
		free(use->fd);
	if (use->id)
		free(use->id);
}

void	close_unused_fds(t_info *use, int child_num)
{
	int	i;

	i = 0;
	while (i < use->cmd_nbr - 1)
	{
		if (i == child_num)
		{
			if (child_num != use->cmd_nbr - 1 && use->fd[i][0] >= 0)
				close(use->fd[i][0]);
			else if (use->fd[i][1] >= 0)
				close(use->fd[i][1]);
		}
		else if (i == child_num - 1 && use->fd[i][1] >= 0)
			close(use->fd[i][1]);
		else
		{
			if (use->fd[i][0] >= 0)
				close(use->fd[i][0]);
			if (use->fd[i][1])
				close(use->fd[i][1]);
		}
		i++;
	}
}
