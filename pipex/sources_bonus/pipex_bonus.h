/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:57:13 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/12 21:20:06 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0

typedef struct s_info
{
	pid_t	*id;
	int		*fd[2];
}			t_info;

// Processes
void	start_processes(int argc, char **argv, char **envp, t_info *use);
void	child_start_process(int *fd[2], char **argv, char **envp);
void	child_next_process(int *fd[2], int argc, char **argv, char **envp);
void	child_end_process(int *fd[2], char **argv, char **envp);

// Path
void	get_path(char *cmd, char **envp, char **path);
void	get_path_index(char **envp, int *index);

// Utils
void	read_input(int argc, char **envp, t_info *use);
void	error_message(char *str, char *cmd, int code);
void	free_and_close(int fd, char **paths, char *path, char *path_cmd);
void	close_fds(int *fd[2]);
int		get_argc(char **argv);

#endif
