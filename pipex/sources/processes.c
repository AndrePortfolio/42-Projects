/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/10 21:21:23 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_start_process(int *fd, char **argv, char **envp)
{
	int		infile;
	char	**cmd;
	char	*path;

	close(fd[READ_END]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_message("Failed to open infile", NULL);
	if (dup2(infile, STDIN_FILENO) == -1)
		error_message("Error setting infile to STDIN", NULL);
	close(infile);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL);
	close(fd[WRITE_END]);
	cmd = ft_split(argv[2], ' ');
	get_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_freematrix(cmd);
		error_message("pipex: command not found: ", argv[2]);
	}
}

void	child_end_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	close(fd[WRITE_END]);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_message("Failed to open outfile", NULL);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_message("Error setting outfile to STDOUT", NULL);
	close(outfile);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL);
	close(fd[READ_END]);
	cmd = ft_split(argv[3], ' ');
	get_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_freematrix(cmd);
		error_message("pipex: command not found: ", argv[3]);
	}
}
