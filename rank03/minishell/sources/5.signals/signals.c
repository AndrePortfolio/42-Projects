/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:46:43 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:46:44 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* replaces line but doesn't show new prompt */
void	sigint_handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
}

/* replaces line and shows prompt (is called if no prompt printed yet)*/
void	sigint_handler_prompt(int sig)
{
	t_info	info;

	(void)sig;
	info = exit_info(NULL);
	info.info->status = 130;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

t_info	exit_info(t_shell *shell)
{
	static t_info	info;

	if (shell)
		info.info = shell;
	return (info);
}

void	heredoc_handler(int sig)
{
	t_info	info;

	(void)sig;
	info = exit_info(NULL);
	clean_up(info.info, false);
	if (info.info->fds_heredoc[WRITE_END] > 0)
		close(info.info->fds_heredoc[WRITE_END]);
	exit(130);
}

/* receives signals and calls sigint handler with a certain int sig */
void	signals(int n)
{
	signal(SIGQUIT, SIG_IGN);
	if (n == MAIN)
		signal(SIGINT, sigint_handler);
	else if (n == MAIN_PROMPT)
		signal(SIGINT, sigint_handler_prompt);
	else if (n == CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (n == HERE)
		signal(SIGINT, heredoc_handler);
	else if (n == IGN)
		signal(SIGINT, SIG_IGN);
}
