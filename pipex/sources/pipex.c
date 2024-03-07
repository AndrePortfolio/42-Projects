/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/07 21:19:17 by andrealbuqu      ###   ########.fr       */
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

// USING EXECVE FUNCTION
// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;

// 	int	i = -1;
// 	static int flag = 0;

// 	while (envp[++i])
// 		ft_putendl_fd(envp[i], 1);
// 	if (flag)
// 		return 0;
// 	write(1, "\n", 1);
// 	if (execve("./pipex_test", argv, envp))
// 		flag++;
// 	perror("execve");
// 	return (1);
// }


// USING THE DUP FUNCTION
// int	main(int argc, char **argv)
// {
// 	int fd;

// 	(void)argc;
// 	fd = open(argv[1], O_WRONLY | O_CREAT, 0x777);
// 	if (fd < 0)
// 		perror("Error opening file\n");
// 	if (dup2(fd, 1) == -1)
// 		perror("Error setting file to STDOUT\n");
// 	write(1, "hello\n", 6);
// 	close(fd);
// }

// USING PIPES AND FORK
// int main(void)
// {
// 	int	id;
// 	int	pipe1[2]; // P -> C
// 	int	pipe2[2]; // C -> P

// 	if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
// 	{
// 		perror("Error creating pipe(s)");
// 		return (1);
// 	}
// 	id = fork();
// 	if (id == -1)
// 		return (1);
// 	if (id == 0)
// 	{
// 		int y;

// 		close(pipe1[1]);
// 		close(pipe2[0]);

// 		if (read(pipe1[0], &y, sizeof(y)) == -1)
// 			perror("Error reading from pipe1");
// 		ft_printf("Child read %d\n", y);
// 		y *= 2;
// 		if (write(pipe2[1], &y, sizeof(y)) == -1)
// 			perror("Error writting to pipe2");
// 		ft_printf("Child wrote %d\n", y);

// 		close(pipe1[0]);
// 		close(pipe2[1]);
// 	}
// 	else
// 	{
// 		int x = 10;

// 		close(pipe1[0]);
// 		close(pipe2[1]);

// 		if (write(pipe1[1], &x, sizeof(x)) == -1)
// 			perror("Error writting to pipe1");
// 		ft_printf("Parent wrote %d\n", x);
// 		if (read(pipe2[0], &x, sizeof(x)) == -1)
// 			perror("Error reading from pipe2");
// 		ft_printf("Parent read %d\n", x);

// 		close(pipe1[1]);
// 		close(pipe2[0]);
// 	}
// 	return (0);
// }
