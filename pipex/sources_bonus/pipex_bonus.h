/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:57:13 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/18 23:53:35 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0
# define INPUT 0

typedef struct s_info
{
	pid_t	*id;
	int		**fd;
	int		cmd_nbr;
	bool	here_doc;
	int		infile;
	int		outfile;
}			t_info;

// Processes
void	start_processes(char **argv, char **envp, t_info *use);
void	child_start_process(t_info *use, char **argv, char **envp);
void	child_next_process(t_info *use, char **argv, char **envp, int i);
void	child_end_process(t_info *use, char **argv, char **envp, int i);

// Path
void	get_path(char *cmd, char **envp, char **path, t_info *use);
void	get_path_index(char **envp, int *index, t_info *use, char *cmd);
char	*check_path(char *cmd, int *flag, char **envp, t_info *use);
void	invalid_path(char **cmd_arg, t_info *use, char *cmd);

// Close Program
void	error_message(t_info *use, char *str, char *cmd, int code);
void	free_and_close(int fd, char **paths, char *path, char *path_cmd);
void	close_all_fds(t_info *use);
void	close_unused_fds(t_info *use, int child_num);
int		wait_pids(int argc, t_info *use);
void	free_all(t_info *use);
void	error_message2(char *str);

// Utils
void	read_input(int argc, char **argv, t_info *use);
void	init_here_doc(char *limiter, t_info *use);
void	get_files(t_info *use, int argc, char **argv);
char	**get_cmd_arg(t_info *use, char **argv, int i);
void	check_here_doc(int argc, char **argv, t_info *use);

#endif
