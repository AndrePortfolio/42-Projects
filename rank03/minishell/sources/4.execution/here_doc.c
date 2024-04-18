/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:20:00 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 14:21:14 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_child_here(t_shell *s, char *limit, char *line, int pipe_nbr)
{
	signals(HERE);
	close(s->fds_heredoc[READ_END]);
	while (true)
	{
		pipe_nbr = s->pipe_nbr;
		while (pipe_nbr-- > 0)
			ft_putstr_fd("pipe ", 1);
		line = readline("heredoc> ");
		if (!line)
		{
			ft_putendl_fd("minishell: warning: here-document \
delimited by end-of-file", STDERR_FILENO);
			break ;
		}
		if (ft_strlen(line) != 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strcmp(line, limit) == 0)
			break ;
		ft_putendl_fd(line, s->fds_heredoc[WRITE_END]);
		free(line);
	}
	close(s->fds_heredoc[WRITE_END]);
	clean_up(s, false);
	exit (0);
}

bool	init_heredoc(char *limiter, t_shell *shell, int f_in, int f_out)
{
	pid_t	id;
	int		status;
	char	*line;
	int		pipe_nbr;

	shell->here_doc = true;
	pipe_nbr = 0;
	line = NULL;
	id = fork();
	if (id == 0)
		exec_child_here(shell, limiter, line, pipe_nbr);
	signals(MAIN);
	close(shell->fds_heredoc[WRITE_END]);
	waitpid(id, &status, 0);
	if (WEXITSTATUS(status) == 130)
	{
		shell->status = 130;
		return (false);
	}
	if (f_in != 1 && f_out != 1)
		shell->status = status;
	return (true);
}

void	reset_heredoc_fds(t_shell *shell)
{
	if (shell->fds_heredoc[READ_END])
		close(shell->fds_heredoc[READ_END]);
	if (shell->fds_heredoc[WRITE_END])
		close(shell->fds_heredoc[WRITE_END]);
	shell->fds_heredoc[WRITE_END] = 0;
	shell->fds_heredoc[READ_END] = 0;
}
