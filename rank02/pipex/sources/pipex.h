/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:57:13 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/19 00:17:56 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0

// Processes
void	child_start_process(int *fd, char **argv, char **envp);
void	child_end_process(int *fd, char **argv, char **envp);

// Path
void	get_path(char *cmd, char **envp, char **path);
void	get_path_index(char **envp, int *index, char *cmd);
char	*check_path(char *cmd, int *flag, char **envp);
void	invalid_path(char **cmd, int file, char *argv, int *fd);
char	**check_command(char **argv, int file, int *fd, int code);

// Close Program
void	error_message(char *str, char *cmd, int code);
void	c_error_message(char *str, char *cmd, int code, int *fd);
void	close_fds(int *fd, int file);
void	free_and_close(int fd, char **paths, char *path, char *path_cmd);

#endif
