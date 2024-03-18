/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/18 16:43:41 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_start_process(int *fd, char **argv, char **envp)
{
	int		infile;
	char	**cmd;
	char	*path;
	int		flag;

	flag = 1;
	path = NULL;
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		c_error_message("Failed to open infile", NULL, 1, fd);
	if (dup2(infile, STDIN_FILENO) == -1)
		c_error_message("Error setting infile to STDIN", NULL, 1, fd);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		c_error_message("Error setting pipe write end to STDOUT", NULL, 1, fd);
	cmd = check_command(argv, infile, fd, 1);
	path = check_path(cmd[0], &flag, envp);
	if (!path)
		invalid_path(cmd, infile, argv[2], fd);
	close_fds(fd, infile);
	execve(path, cmd, envp);
	if (flag)
		free(path);
	ft_freematrix(cmd);
	error_message("pipex: command not found: ", argv[2], 127);
}

void	child_end_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;
	int		flag;

	flag = 1;
	path = NULL;
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		c_error_message("Failed to open outfile", NULL, 1, fd);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		c_error_message("Error setting outfile to STDOUT", NULL, 1, fd);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
		c_error_message("Error setting pipe read end to STDIN", NULL, 1, fd);
	cmd = check_command(argv, outfile, fd, 127);
	path = check_path(cmd[0], &flag, envp);
	if (!path)
		invalid_path(cmd, outfile, argv[3], fd);
	close_fds(fd, outfile);
	execve(path, cmd, envp);
	if (flag)
		free(path);
	ft_freematrix(cmd);
	error_message("pipex: command not found: ", argv[3], 127);
}
