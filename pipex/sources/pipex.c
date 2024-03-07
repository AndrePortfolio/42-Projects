/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/07 23:45:07 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *str, char *cmd)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
	exit (1);
}

char	*get_path(char *cmd, char **envp)
{
	char **paths;
	char *path;
	char *path_cmd;
	int	i;
	int j;
	int fd;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			while (paths[j])
			{
				path = ft_strjoin(paths[j], "/");
				path_cmd = ft_strjoin(path, cmd);
				free(path);
				fd = open(path_cmd, O_RDONLY);
				if (fd >= 0)
				{
					close(fd);
					ft_freematrix(paths);
					return (path_cmd);
				}
				free(path_cmd);
				j++;
			}
		}
		i++;
	}
	close(fd);
	ft_freematrix(paths);
	return (NULL);
}

void	child_process(int *fd, char **argv, char **envp)
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
	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_freematrix(cmd);
		error_message("pipex: command not found: ", argv[2]);
	}
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	close(fd[WRITE_END]);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0x777);
	if (outfile < 0)
		error_message("Failed to open outfile", NULL);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_message("Error setting outfile to STDOUT", NULL);
	close(outfile);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
		error_message("Error setting pipe read end to STDIN", NULL);
	close(fd[READ_END]);
	cmd = ft_split(argv[3], ' ');
	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_freematrix(cmd);
		error_message("pipex: command not found: ", argv[3]);
	}
}

int main(int argc, char **argv, char **envp)
{
	int	id;
	int	fd[2];

	if (argc != 5)
		error_message("Invalid number of arguments", NULL);
	if (pipe(fd) == -1)
		error_message("Failed to create the pipe(s)", NULL);
	id = fork();
	if (id == 0)
		child_process(fd, argv, envp);
	else
	{
		wait(NULL);
		parent_process(fd, argv, envp);
	}
	return (0);
}
