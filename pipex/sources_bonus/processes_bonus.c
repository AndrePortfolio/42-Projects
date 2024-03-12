/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/12 03:10:37 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_start_process(int (*fd)[2], char **argv, char **envp)
{
	int		infile;
	char	**cmd_arg;
	char	*cmd;
	char	*path;

	path = NULL;
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_message("Failed to open infile", NULL, 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		error_message("Error setting infile to STDIN", NULL, 1);
	close(infile);
	if (dup2(fd[0][WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL, 1);
	close_fds(fd);
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

void	child_next_process(char **argv, char **envp, int argc, info_t **use)
{
	int	n;

	if (argc == 0)
		argc = get_argc(argv);
	n = argc - 3;
	if (argc > 6)
		child_next_process(argv, envp, argc - 1, use);
	(*use)->id[n] = fork();
	if ((*use)->id[n] == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if ((*use)->id[n] == 0)
		execute_next_process((*use)->fd, argc, argv, envp);
}

void	execute_next_process(int (*fd)[2], int argc, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd;
	char	*path;

	path = NULL;
	if (dup2(fd[1][READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL, 1);
	if (dup2(fd[0][WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL, 1);
	close_fds(fd);
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

void	child_end_process(int (*fd)[2], char **argv, char **envp)
{
	int		outfile;
	char	**cmd_arg;
	char	*path;
	int		argc;
	char	*cmd;

	path = NULL;
	argc = get_argc(argv);
	outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_message("Failed to open outfile", NULL, 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_message("Error setting outfile to STDOUT", NULL, 1);
	close(outfile);
	if (dup2(fd[0][READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL, 1);
	close_fds(fd);
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

void	parent_process(char **argv, char **envp, info_t *use)
{
	int		argc;

	argc = get_argc(argv);
	use->id[1] = fork();
	if (use->id[1] == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (use->id[1] == 0 && argc > 5)
		child_next_process(argv, envp, 0, &use);
	else if (use->id[1] == 0)
		child_end_process(use->fd, argv, envp);
	else
	{
		use->id[2] = fork();
		if (use->id[2] == -1)
			error_message("Failed to execute the fork", NULL, 1);
		else if (use->id[2] == 0)
			if (argc > 5)
				child_end_process(use->fd, argv, envp);
	}
}
