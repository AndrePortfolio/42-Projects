/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/12 13:24:27 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_input(int argc, char **envp, t_info *use)
{
	if (argc < 5)
		error_message("Invalid number of arguments", NULL, 1);
	if (!envp)
		error_message("No environmental variables", NULL, 1);
	use->id = malloc(sizeof(pid_t) * (argc - 2));
	if (!use->id)
		error_message("Memory allocation failed", NULL, 1);
}

void	error_message(char *str, char *cmd, int code)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
	free(cmd);
	exit (code);
}

void	free_and_close(int fd, char **paths, char *path, char *path_cmd)
{
	if (!path_cmd)
	{
		if (path)
			free(path);
		close(fd);
		ft_freematrix(paths);
	}
	else
	{
		free(path);
		free(path_cmd);
	}
}

void	close_fds(int (*fd)[2])
{
	if (fd[0][WRITE_END] >= 0)
		close(fd[1][WRITE_END]);
	if (fd[0][READ_END] >= 0)
		close(fd[1][READ_END]);
	if (fd[1][WRITE_END] >= 0)
		close(fd[1][WRITE_END]);
	if (fd[1][READ_END] >= 0)
		close(fd[1][READ_END]);
}

int	get_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
