/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/24 19:17:51 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	read_input(int argc, char **argv)
{
	if (argc != 5)
		error_message("Invalid number of arguments");
	(void)argv;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	const char *currdir = NULL;
	int i = 0;

	(void)argc;
	(void)argv;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0) {
			currdir = envp[i] + 4;
			break ;
		}
		i++;
	}
	if (!currdir)
	{
		write(STDERR_FILENO, "PWD environment variable not found.\n", 35);
		return (1);
	}
	int pipe_fd[2];
	pid_t child_pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	if ((child_pid = fork()) == -1)
	{
		perror("fork");
		return 1;
	}
	if (child_pid == 0) // Child process
	{
		// Redirect stdout to the write end of the pipe
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);

		// Execute ls command in the specified directory
		char *ls_args[] = {"ls", (char *)currdir, NULL};
		execve("/bin/ls", ls_args, envp);

		// If execlp fails
		perror("execlp");
		exit(1);
	}
	else // Parent process
	{
		// Wait for the child to finish
		waitpid(child_pid, NULL, 0);

		// Read and print the output from the read end of the pipe
		char buffer[BUFFER_SIZE];
		int bytes_read;

		close(pipe_fd[1]);  // Close the write end of the pipe

		while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, bytes_read);

		close(pipe_fd[0]);  // Close the read end of the pipe
	}
	return (0);
}


