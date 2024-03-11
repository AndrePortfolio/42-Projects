/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/11 20:45:39 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_start_process(int *fd, char **argv, char **envp)
{
	int		infile;
	char	**cmd_arg;
	char	*cmd;
	char	*path;

	path = NULL;
	close(fd[READ_END]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_message("Failed to open infile", NULL, 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		error_message("Error setting infile to STDIN", NULL, 1);
	close(infile);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL, 1);
	close(fd[WRITE_END]);
	cmd_arg = ft_split(argv[2], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	get_path(cmd_arg[0], envp, &path);
	if (!path)
	{
		ft_freematrix(cmd_arg);
		error_message("pipex: command not found: ", cmd, 127);
	}
	execve(path, cmd_arg, envp);
	free(path);
	ft_freematrix(cmd_arg);
}

void	child_next_process(int (*fd)[2], int argc, char **argv, char **envp)
{
	int		id;

	if (argc == 0)
		argc = get_argc(argv);
	if (argc > 6)
		child_next_process(fd, argc - 1, argv, envp);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (id == 0)
		execute_next_process(fd, argc, argv, envp);
}

void	execute_next_process(int (*fd)[2], int argc, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd;
	char	*path;

	path = NULL;
	close(fd[1][WRITE_END]);
	close(fd[0][READ_END]);
	if (dup2(fd[1][READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL, 1);
	if (dup2(fd[0][WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL, 1);
	close(fd[0][READ_END]);
	close(fd[1][WRITE_END]);
	cmd_arg = ft_split(argv[argc - 3], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	get_path(cmd_arg[0], envp, &path);
	if (!path)
	{
		ft_freematrix(cmd_arg);
		error_message("pipex: command not found: ", cmd, 127);
	}
	execve(path, cmd_arg, envp);
	free(path);
	ft_freematrix(cmd_arg);
}

void	child_end_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	**cmd_arg;
	char	*path;
	int		argc;
	char	*cmd;

	path = NULL;
	argc = get_argc(argv);
	close(fd[WRITE_END]);
	outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_message("Failed to open outfile", NULL, 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_message("Error setting outfile to STDOUT", NULL, 1);
	close(outfile);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL, 1);
	close(fd[READ_END]);
	cmd_arg = ft_split(argv[argc - 2], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	get_path(cmd_arg[0], envp, &path);
	if (!path)
	{
		ft_freematrix(cmd_arg);
		error_message("pipex: command not found: ", cmd, 127);
	}
	execve(path, cmd_arg, envp);
	free(path);
	ft_freematrix(cmd_arg);
}

void	parent_process(int (*fd)[2], char **argv, char **envp, int *status)
{
	int		argc;
	pid_t	id;

	argc = get_argc(argv);
	id = fork();
	if (id == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (id == 0 && argc > 5)
		child_next_process(fd, 0, argv, envp);
	else if (id == 0)
		child_end_process(fd[1], argv, envp);
	else
		child_last_process(fd, argv, envp, status);
	close_fds(fd);
	waitpid(id, NULL, 0);
}
