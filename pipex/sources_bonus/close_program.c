/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:24:51 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/14 18:20:04 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_message(t_info *use, char *str, char *cmd, int code)
{
	ft_putstr_fd(str, 2);
	if (cmd)
	{
		ft_putendl_fd(cmd, 2);
		free(cmd);
	}
	else
		ft_putchar_fd('\n', 2);
	free_all(use);
	exit (code);
}

void	invalid_arguments(char *str)
{
	ft_putstr_fd(str, 2);
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

int	wait_pids(int argc, t_info *use)
{
	int	status;
	int	i;

	i = 0;
	if (use->here_doc)
	{
		while (argc - 5 > 0)
		{
			waitpid(use->id[i++], NULL, 0);
			argc--;
		}
	}
	else
	{
		while (argc - 4 > 0)
		{
			waitpid(use->id[i++], NULL, 0);
			argc--;
		}
	}
	waitpid(use->id[i], &status, 0);
	return (status);
}
