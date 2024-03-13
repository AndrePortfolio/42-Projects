/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/13 22:27:32 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	start_processes(char **argv, char **envp, t_info *use)
{
	int	cmds;
	int i;

	i = 1;
	cmds = use->cmd_nbr;
	use->id[0] = fork();
	if (use->id[0] == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (use->id[0] == 0)
		child_start_process(use, argv, envp);
	while (cmds > 2)
	{
		use->id[i] = fork();
		if (use->id[i] == -1)
			error_message("Failed to execute the fork", NULL, 1);
		else if (use->id[i] == 0)
			child_next_process(use, argv, envp, i);
		cmds--;
		i++;
	}
	use->id[i] = fork();
	if (use->id[i] == -1)
		error_message("Failed to execute the fork", NULL, 1);
	else if (use->id[i] == 0)
		child_end_process(use, argv, envp, i);
}

void	child_start_process(t_info *use, char **argv, char **envp)
{
	int		infile;
	char	**cmd_arg;
	char	*cmd;
	char	*path;

	path = NULL;
	close_unused_fds(use, 0);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_message("Failed to open infile", NULL, 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		error_message("Error setting infile to STDIN", NULL, 1);
	if (dup2(use->fd[0][WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL, 1);
	if (!argv[2][0])
		error_message("pipex: permission denied: ", NULL, 1);
	cmd_arg = ft_split(argv[2], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	get_path(cmd_arg[0], envp, &path);
	if (!path)
	{
		ft_freematrix(cmd_arg);
		error_message("pipex: command not found: ", cmd, 127);
	}
	close(infile);
	close_all_fds(use);
	execve(path, cmd_arg, envp);
	free(path);
	ft_freematrix(cmd_arg);
}

void	child_next_process(t_info *use, char **argv, char **envp, int i)
{
	char	**cmd_arg;
	char	*cmd;
	char	*path;

	path = NULL;
	close_unused_fds(use, i);
	if (dup2(use->fd[i - 1][READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL, 1);
	if (dup2(use->fd[i][WRITE_END], STDOUT_FILENO) == -1)
		error_message("Error setting pipe write end to STDOUT", NULL, 1);
	if (!argv[2 + i][0])
		error_message("pipex: permission denied: ", NULL, 1);
	cmd_arg = ft_split(argv[2 + i], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	get_path(cmd_arg[0], envp, &path);
	if (!path)
	{
		ft_freematrix(cmd_arg);
		error_message("pipex: command not found: ", cmd, 1);
	}
	close_all_fds(use);
	execve(path, cmd_arg, envp);
	free(path);
	ft_freematrix(cmd_arg);
}

void	child_end_process(t_info *use, char **argv, char **envp, int i)
{
	int		outfile;
	char	**cmd_arg;
	char	*path;
	char	*cmd;

	path = NULL;
	close_unused_fds(use, i);
	outfile = open(argv[3 + i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_message("Failed to open outfile", NULL, 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_message("Error setting outfile to STDOUT", NULL, 1);
	if (dup2(use->fd[i - 1][READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL, 1);
	if (!argv[2 + i][0])
		error_message("pipex: permission denied: ", NULL, 127);
	cmd_arg = ft_split(argv[2 + i], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	get_path(cmd_arg[0], envp, &path);
	if (!path)
	{
		ft_freematrix(cmd_arg);
		error_message("pipex: command not found: ", cmd, 127);
	}
	close(outfile);
	close_all_fds(use);
	execve(path, cmd_arg, envp);
	free(path);
	ft_freematrix(cmd_arg);
}
