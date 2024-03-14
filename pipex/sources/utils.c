/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:27:11 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/14 18:27:20 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(char *cmd, char **envp, char **path)
{
	char	**paths;
	char	*single_path;
	char	*path_cmd;
	int		fd;
	int		i;

	get_path_index(envp, &i);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		single_path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(single_path, cmd);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
		{
			*path = path_cmd;
			free_and_close(fd, paths, single_path, NULL);
			return ;
		}
		free_and_close(fd, paths, single_path, path_cmd);
		i++;
	}
	free_and_close(fd, paths, NULL, NULL);
}

void	get_path_index(char **envp, int *index)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			*index = i;
			return ;
		}
		i++;
	}
}

void	error_message(char *str, char *cmd, int code)
{
	ft_putstr_fd(str, 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putchar_fd('\n', 2);
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
