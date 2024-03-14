/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/14 02:37:22 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_input(int argc, char **argv, char **envp, t_info *use)
{
	int	i;

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

void	init_here_doc(char *limiter, t_info *use)
{
	char	*line;
	int		pipe_nbr;
	int		fd;

	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (true)
	{
		pipe_nbr = use->cmd_nbr - 1;
		while (pipe_nbr-- > 0)
			ft_putstr_fd("pipe ", 1);
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
		use->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND,
				0644);
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

char	**get_cmd_arg(t_info *use, char **argv, int i)
{
	char	**cmd_arg;

	if (use->here_doc)
	{
		if (!argv[3 + i][0])
			error_message("pipex: permission denied: ", NULL, 127);
		cmd_arg = ft_split(argv[3 + i], ' ');
	}
	else
	{
		if (!argv[2 + i][0])
			error_message("pipex: permission denied: ", NULL, 127);
		cmd_arg = ft_split(argv[2 + i], ' ');
	}
	return (cmd_arg);
}
