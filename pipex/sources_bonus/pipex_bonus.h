/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:57:13 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/13 19:59:12 by andre-da         ###   ########.fr       */
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
	int		**fd;
	int		cmd_nbr;
}			t_info;

// Processes
void	start_processes(char **argv, char **envp, t_info *use);
void	child_start_process(t_info *use, char **argv, char **envp);
void	child_next_process(t_info *use, char **argv, char **envp, int i);
void	child_end_process(t_info *use, char **argv, char **envp, int i);
// Path
void	get_path(char *cmd, char **envp, char **path);
void	get_path_index(char **envp, int *index);

// Utils
void	read_input(int argc, char **envp, t_info *use);
void	error_message(char *str, char *cmd, int code);
void	free_and_close(int fd, char **paths, char *path, char *path_cmd);
void	close_all_fds(t_info *use);
void	close_unused_fds(t_info *use, int i);

#endif
