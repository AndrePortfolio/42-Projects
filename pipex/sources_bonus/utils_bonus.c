/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/14 16:38:31 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_files(t_info *use, int argc, char **argv)
{
	if (use->here_doc)
	{
		init_here_doc(argv[2], use);
		use->infile = open("here_doc", O_RDONLY);
		if (use->infile < 0)
		{
			unlink("here_doc");
			error_message(use, "Failed to open infile", NULL, 1);
		}
		use->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND,
				0644);
		if (use->outfile < 0)
			error_message(use, "Failed to open outfile", NULL, 1);
	}
	else
	{
		use->infile = open(argv[1], O_RDONLY);
		if (use->infile < 0)
			error_message(use, "Failed to open infile", NULL, 1);
		use->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (use->outfile < 0)
			error_message(use, "Failed to open outfile", NULL, 1);
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

char	**get_cmd_arg(t_info *use, char **argv, int i)
{
	char	**cmd_arg;

	if (use->here_doc)
	{
		if (!argv[3 + i][0])
			error_message(use, "pipex: permission denied: ", NULL, 127);
		cmd_arg = ft_split(argv[3 + i], ' ');
	}
	else
	{
		if (!argv[2 + i][0])
			error_message(use, "pipex: permission denied: ", NULL, 127);
		cmd_arg = ft_split(argv[2 + i], ' ');
	}
	return (cmd_arg);
}
