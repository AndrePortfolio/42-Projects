/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/11 00:45:53 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	child_next_process(int (*fd)[2], int argc, char **argv, char **envp)
{
	int		id;

	if (argc == 0)
		argc = get_argc(argv);
	if (argc > 5)
		child_next_process(fd, argc - 1, argv, envp);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL);
	else if (id == 0)
		execute_next_process(fd, argc, argv, envp);
}

void	execute_next_process(int (*fd)[2], int argc, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	argc = get_argc(argv);
	close(fd[1][WRITE_END]);
	close(fd[0][READ_END]);
	if (dup2(fd[1][READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL);
	if (dup2(fd[0][WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL);
	close(fd[0][READ_END]);
	close(fd[1][WRITE_END]);
	cmd = ft_split(argv[argc - 2], ' ');
	get_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_freematrix(cmd);
		error_message("pipex: command not found: ", argv[argc - 2]);
	}
}

void	child_end_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;
	int		argc;

	argc = get_argc(argv);
	close(fd[WRITE_END]);
	outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_message("Failed to open outfile", NULL);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_message("Error setting outfile to STDOUT", NULL);
	close(outfile);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL);
	close(fd[READ_END]);
	cmd = ft_split(argv[argc - 2], ' ');
	get_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_freematrix(cmd);
		error_message("pipex: command not found: ", argv[argc - 2]);
	}
}

void	parent_process(int id, int (*fd)[2], char **argv, char **envp)
{
	int	argc;

	argc = get_argc(argv);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL);
	else if (id == 0 && argc > 5)
		child_next_process(fd, 0, argv, envp);
	else if (id == 0)
		child_end_process(fd[1], argv, envp);
	else
	{
		id = fork();
		if (id == -1)
			error_message("Failed to execute the fork", NULL);
		else if (id == 0)
			child_last_process(fd, argv, envp);
		else
			close_fds(fd);
	}
}
