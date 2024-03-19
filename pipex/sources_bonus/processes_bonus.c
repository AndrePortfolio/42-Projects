/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:52:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/19 00:01:54 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	start_processes(char **argv, char **envp, t_info *use)
{
	int	cmds;
	int	i;

	i = 1;
	cmds = use->cmd_nbr;
	use->id[0] = fork();
	if (use->id[0] == -1)
		error_message(use, "Failed to execute the fork", NULL, 1);
	else if (use->id[0] == 0)
		child_start_process(use, argv, envp);
	while (cmds > 2)
	{
		use->id[i] = fork();
		if (use->id[i] == -1)
			error_message(use, "Failed to execute the fork", NULL, 1);
		else if (use->id[i] == 0)
			child_next_process(use, argv, envp, i);
		cmds--;
		i++;
	}
	use->id[i] = fork();
	if (use->id[i] == -1)
		error_message(use, "Failed to execute the fork", NULL, 1);
	else if (use->id[i] == 0)
		child_end_process(use, argv, envp, i);
}

void	child_start_process(t_info *use, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd;
	char	*path;
	int		flag;

	flag = 1;
	path = NULL;
	close_unused_fds(use, 0);
	if (use->infile < 0)
		error_message(use, "Failed to open infile", NULL, 1);
	if (dup2(use->infile, STDIN_FILENO) == -1)
		error_message(use, "Error setting infile to STDIN", NULL, 1);
	if (dup2(use->fd[0][WRITE_END], STDOUT_FILENO) == -1)
		error_message(use, "Error setting pipe write end to STDOUT", NULL, 1);
	cmd_arg = get_cmd_arg(use, argv, 0);
	cmd = ft_strdup(cmd_arg[0]);
	path = check_path(cmd_arg[0], &flag, envp, use);
	if (!path)
		invalid_path(cmd_arg, use, cmd);
	close_all_fds(use);
	free(cmd);
	execve(path, cmd_arg, envp);
	if (flag)
		free(path);
	error_message(use, "pipex: command not found: ", cmd_arg[0], 127);
}

void	child_next_process(t_info *use, char **argv, char **envp, int i)
{
	char	**cmd_arg;
	char	*cmd;
	char	*path;
	int		flag;

	flag = 1;
	path = NULL;
	close_unused_fds(use, i);
	if (dup2(use->fd[i - 1][READ_END], STDIN_FILENO) == -1)
		error_message(use, "Error setting pipe read end to STDIN", NULL, 1);
	if (dup2(use->fd[i][WRITE_END], STDOUT_FILENO) == -1)
		error_message(use, "Error setting pipe write end to STDOUT", NULL, 1);
	cmd_arg = get_cmd_arg(use, argv, i);
	cmd = ft_strdup(cmd_arg[0]);
	path = check_path(cmd_arg[0], &flag, envp, use);
	if (!path)
		invalid_path(cmd_arg, use, cmd);
	close_all_fds(use);
	free(cmd);
	execve(path, cmd_arg, envp);
	if (flag)
		free(path);
	error_message(use, "pipex: command not found: ", cmd_arg[0], 127);
}

void	child_end_process(t_info *use, char **argv, char **envp, int i)
{
	char	**cmd_arg;
	char	*path;
	char	*cmd;
	int		flag;

	flag = 1;
	path = NULL;
	close_unused_fds(use, i);
	if (dup2(use->outfile, STDOUT_FILENO) == -1)
		error_message(use, "Error setting outfile to STDOUT", NULL, 1);
	if (dup2(use->fd[i - 1][READ_END], STDIN_FILENO) == -1)
		error_message(use, "Error setting pipe read end to STDIN", NULL, 1);
	cmd_arg = get_cmd_arg(use, argv, i);
	cmd = ft_strdup(cmd_arg[0]);
	path = check_path(cmd_arg[0], &flag, envp, use);
	if (!path)
		invalid_path(cmd_arg, use, cmd);
	close_all_fds(use);
	free(cmd);
	execve(path, cmd_arg, envp);
	if (flag)
		free(path);
	error_message(use, "pipex: command not found: ", cmd_arg[0], 127);
}
