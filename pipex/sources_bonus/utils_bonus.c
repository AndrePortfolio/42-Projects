/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/14 01:54:07 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_here_doc(char *limiter, t_info *use)
{
	char *line;
	int	fd;
	int	pipe_nbr;

	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (true)
	{
		pipe_nbr = use->cmd_nbr - 1;
		while (pipe_nbr > 0)
		{
			ft_putstr_fd("pipe ", 1);
			pipe_nbr--;
		}
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(INPUT);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strcmp(line, limiter) == 0)
			break ;
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
}

void	get_files(t_info *use, int argc, char **argv)
{
	if (use->here_doc)
	{
		init_here_doc(argv[2], use);
		use->infile = open("here_doc", O_RDONLY);
		if (use->infile < 0)
		{
			unlink("here_doc");
			error_message("Failed to open infile", NULL, 1);
		}
		use->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (use->outfile < 0)
			error_message("Failed to open outfile", NULL, 1);
	}
	else
	{
		use->infile = open(argv[1], O_RDONLY);
		if (use->infile < 0)
			error_message("Failed to open infile", NULL, 1);
		use->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (use->outfile < 0)
			error_message("Failed to open outfile", NULL, 1);
	}
}

void	read_input(int argc, char **argv, char **envp, t_info *use)
{
	int i;

	if (argv[1] && !ft_strcmp("here_doc", argv[1]))
	{
		if (argc < 6)
			error_message("Invalid number of arguments", NULL, 1);
		use->here_doc = true;
		use->cmd_nbr = argc - 4;
	}
	else
	{
		if (argc < 5)
			error_message("Invalid number of arguments", NULL, 1);
		use->here_doc = false;
		use->cmd_nbr = argc - 3;
	}
	get_files(use, argc, argv);
	if (!envp)
		error_message("No environmental variables", NULL, 1);
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
