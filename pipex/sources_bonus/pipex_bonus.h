/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:57:13 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/10 20:29:47 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0

// Processes
void	get_path(char *cmd, char **envp, char **path);
void	child_start_process(int *fd, char **argv, char **envp);
void	child_end_process(int *fd, int argc, char **argv, char **envp);
void	child_next_process(int (*fd)[2], int argc, char **argv, char **envp);

// Utils
void	read_input(int argc, char **envp);
void	error_message(char *str, char *cmd);
void	get_path_index(char **envp, int *index);
void	free_and_close(int fd, char **paths, char *path, char *path_cmd);

#endif
