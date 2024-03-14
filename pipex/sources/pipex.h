/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:57:13 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/14 02:45:38 by andrealbuqu      ###   ########.fr       */
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
void	close_fds(int *fd, int file);

// Utils
void	get_path(char *cmd, char **envp, char **path);
void	get_path_index(char **envp, int *index);
void	read_input(int argc, char **envp);
void	error_message(char *str, char *cmd, int code);
void	free_and_close(int fd, char **paths, char *path, char *path_cmd);

#endif
