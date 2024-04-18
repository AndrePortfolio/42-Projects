/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:27:26 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 17:49:46 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_path(char *cmd, char **envp, int *flag)
{
	char	*path;

	path = NULL;
	if (ft_strncmp("/usr/bin/", cmd, 9) == 0
		|| ft_strncmp("/bin/", cmd, 5) == 0)
	{
		path = cmd;
		*flag = 0;
	}
	else if (!*(envp) || !envp
		|| ft_strcmp(*envp, "VALGRIND_LIB=/usr/libexec/valgrind") == 0)
		path = ft_strjoin("/usr/bin/", cmd);
	else
		path = get_path(cmd, envp);
	return (path);
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
	*index = -1;
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*single_path;
	char	*path_cmd;
	int		fd;
	int		i;

	get_path_index(envp, &i);
	if (i == -1)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		single_path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(single_path, cmd);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
		{
			free_and_close(fd, paths, single_path, NULL);
			return (path_cmd);
		}
		free_and_close(fd, paths, single_path, path_cmd);
	}
	free_and_close(fd, paths, NULL, NULL);
	return (NULL);
}

void	free_and_close(int fd, char **paths, char *path, char *path_cmd)
{
	if (!path_cmd)
	{
		if (path)
			free(path);
		if (fd >= 0)
			close(fd);
		ft_freematrix(paths);
	}
	else
	{
		free(path);
		free(path_cmd);
	}
}

void	invalid_path(char **full_command, t_shell *shell, char *command)
{
	ft_freematrix(full_command);
	if (ft_strncmp(command, "/", 1) == 0)
		child_error_msg(shell, "minishell: Is a directory: ", command, 126);
	child_error_msg(shell, "minishell: command not found: ", command, 127);
}
