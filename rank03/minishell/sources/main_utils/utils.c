/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:57 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 15:41:02 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	increase_shlvl(t_shell *s)
{
	int		i;
	int		temp;
	char	*temp_nbr;

	i = 0;
	temp = 0;
	temp_nbr = NULL;
	while (s->envp[i])
	{
		if (!ft_strncmp(s->envp[i], "SHLVL=", 6))
		{
			temp = ft_atoi(ft_strchr(s->envp[i], '=') + 1);
			free(s->envp[i]);
			temp_nbr = ft_itoa(temp + 1);
			s->envp[i] = ft_strjoin("SHLVL=", temp_nbr);
			free(temp_nbr);
		}
		i++;
	}
}

void	prepare_tokens(t_shell *shell)
{
	expand(shell);
	remove_spaces(&shell->tokens);
	remove_empty_tokens(&shell->tokens);
}

void	close_wait_reset(t_shell *shell)
{
	close_all_fds(shell, false);
	wait_pids(shell);
	reset(shell);
}

void	get_status(t_shell *shell, int status)
{
	if (shell->here_doc)
	{
		waitpid(shell->id[shell->pipe_nbr], &status, 0);
		if (WEXITSTATUS(status))
			shell->status = WEXITSTATUS(status);
		return ;
	}
	if (!shell->error_file)
	{
		shell->status = 0;
		waitpid(shell->id[shell->pipe_nbr], &status, 0);
		if (WIFSIGNALED(status))
		{
			shell->status = WTERMSIG(status) + 128;
			if (shell->status == 131)
				ft_putstr_fd("Quit", STDERR_FILENO);
		}
		else
			shell->status = WEXITSTATUS(status);
	}
}
