/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:17:08 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/20 21:11:40 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_path(char *cmd, char **envp, char **path, t_info *use)
{
	char	**paths;
	char	*single_path;
	char	*path_cmd;
	int		fd;
	int		i;

	get_path_index(envp, &i, use, cmd);
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

void	get_path_index(char **envp, int *index, t_info *use, char *cmd)
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
	error_message(use, "pipex: command not found: ", cmd, 127);
}

char	*check_path(char *cmd, int *flag, char **envp, t_info *use)
{
	char	*path;

	path = NULL;
	if (ft_strncmp("/usr/bin/", cmd, 9) == 0
		|| ft_strncmp("/bin/", cmd, 5) == 0)
	{
		*flag = 0;
		path = cmd;
	}
	else if (!*(envp) || !envp
		|| ft_strcmp(*envp, "VALGRIND_LIB=/usr/libexec/valgrind") == 0)
		path = ft_strjoin("/usr/bin/", cmd);
	else
		get_path(cmd, envp, &path, use);
	return (path);
}

void	invalid_path(char **cmd_arg, t_info *use, char *cmd)
{
	ft_freematrix(cmd_arg);
	close_all_fds(use);
	error_message(use, "pipex: command not found: ", cmd, 127);
}
