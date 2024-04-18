/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:17 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 13:37:41 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clean_up(t_shell *shell, bool print_msg)
{
	int	i;

	close_all_fds(shell, true);
	if (!shell->reseted)
		free_all(shell);
	i = 0;
	while (shell->envp[i])
		free(shell->envp[i++]);
	if (shell->envp)
		free(shell->envp);
	if (shell->pwd)
		free(shell->pwd);
	if (shell->oldpwd)
		free(shell->oldpwd);
	if (print_msg)
		exit_error_message("exit", shell->status);
}

void	error_message(char *message, char *cmd)
{
	ft_putstr_fd(message, STDERR_FILENO);
	if (cmd)
		ft_putendl_fd(cmd, STDERR_FILENO);
	else
		ft_putchar_fd('\n', 2);
}

void	exit_error_message(char *message, int exit_code)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit (exit_code);
}

void	close_all_fds(t_shell *shell, bool in_out)
{
	int	i;

	i = 0;
	if (shell->infile > 0)
		close(shell->infile);
	if (shell->outfile > 0)
		close(shell->outfile);
	while (i < 2)
	{
		if (shell->fd)
		{
			if (shell->fd[shell->i + i][WRITE_END] > 0)
				close(shell->fd[shell->i + i][WRITE_END]);
			if (shell->fd[shell->i + i][READ_END] > 0)
				close(shell->fd[shell->i + i][READ_END]);
		}
		i++;
	}
	if (in_out)
	{
		close(shell->std_fds[0]);
		close(shell->std_fds[1]);
	}
	if (shell->fds_heredoc[READ_END] > 0)
		close(shell->fds_heredoc[READ_END]);
}

void	child_error_msg(t_shell *shell, char *msg, char *cmd, int code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (cmd)
		ft_putendl_fd(cmd, STDERR_FILENO);
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	clean_up(shell, false);
	exit (code);
}
