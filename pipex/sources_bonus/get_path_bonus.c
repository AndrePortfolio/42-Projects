/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:17:08 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/10 21:17:50 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
