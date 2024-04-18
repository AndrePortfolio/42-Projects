/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 15:40:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	loop(t_shell *shell)
{
	while (true)
	{
		signals(MAIN_PROMPT);
		get_prompt(shell);
		signals(MAIN);
		if (!shell->line)
			break ;
		if (*shell->line)
			add_history(shell->line);
		shell->tokens = tokenize(shell);
		shell->reseted = false;
		if (check_tokens(shell->tokens))
		{
			shell->status = 2;
			free_tokens(shell->tokens);
			shell->tokens = NULL;
			continue ;
		}
		prepare_tokens(shell);
		if (!shell->tokens)
			continue ;
		shell->tree = parse_commandline(shell->tokens, shell);
		execute(shell);
		close_wait_reset(shell);
	}
}

void	get_prompt(t_shell *shell)
{
	if (shell->line)
	{
		free(shell->line);
		shell->line = NULL;
	}
	shell->line = readline("minishell$ ");
}

void	wait_pids(t_shell *shell)
{
	t_tree_node	*current;
	int			status;
	int			i;

	i = 0;
	status = 0;
	while (i < shell->pipe_nbr)
	{
		if (shell->id_exec[i])
			waitpid(shell->id[i], NULL, 0);
		i++;
	}
	current = shell->tree;
	while (current && current->right)
		current = current->right;
	if (current->builtin != NULL)
		return ;
	get_status(shell, status);
}

void	reset(t_shell *shell)
{
	free_all(shell);
	reset_fds(shell);
	shell->pipe_nbr = 0;
	shell->builtins = 0;
	shell->tokens = NULL;
	shell->line = NULL;
	shell->here_doc = 0;
	shell->builtins = 0;
	shell->fd = NULL;
	shell->id = NULL;
	shell->i = 0;
	shell->tree = NULL;
	shell->id_exec = NULL;
	shell->error_file = NULL;
	shell->fds_heredoc[READ_END] = 0;
	shell->fds_heredoc[WRITE_END] = 0;
	shell->reseted = true;
}

void	reset_fds(t_shell *shell)
{
	if (shell->fds_heredoc[READ_END])
		close(shell->fds_heredoc[READ_END]);
	if (shell->infile >= 0)
		close(shell->infile);
	shell->infile = 0;
	if (shell->outfile >= 0)
		close(shell->outfile);
	shell->outfile = 0;
	if (dup2(shell->std_fds[0], STDIN_FILENO) == -1)
		error_message("Failed to reset stdin", NULL);
	if (dup2(shell->std_fds[1], STDOUT_FILENO) == -1)
		error_message("Failed to reset stdout", NULL);
}
