/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:27:28 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 14:27:36 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	open_infile(t_shell *s, t_redir_list *curr, int *f_in, int *f_out)
{
	if (s->infile > 0)
	{
		close(s->infile);
		s->infile = 0;
	}
	if (curr->type == RE_INPUT)
		s->infile = open(curr->file, O_RDONLY);
	else if (curr->type == HEREDOC)
	{
		reset_heredoc_fds(s);
		if (pipe(s->fds_heredoc) == -1)
			return (false);
		if (!init_heredoc(curr->file, s, *f_in, *f_out))
			return (false);
		s->infile = s->fds_heredoc[READ_END];
	}
	if (s->infile < 0)
	{
		s->status = 1;
		if (*f_in == 0 && *f_out == 0)
			s->error_file = curr->file;
		*f_in = 1;
	}
	return (true);
}

void	open_outfil(t_shell *s, t_redir_list *curr, int *f_in, int *f_out)
{
	if (s->outfile > 0)
	{
		close(s->outfile);
		s->outfile = 0;
	}
	if (curr->type == RE_OUTPUT)
		s->outfile = open(curr->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (curr->type == APPEND)
		s->outfile = open(curr->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (s->outfile < 0)
	{
		s->status = 1;
		if (*f_in == 0 && *f_out == 0)
			s->error_file = curr->file;
		*f_out = 1;
	}
}

bool	check_access(t_shell *shell, int flag_in, int flag_out)
{
	if (flag_in && access(shell->error_file, R_OK) != 0)
	{
		if (errno == EACCES)
			return (error_message("minishell: permission denied: ",
					shell->error_file), false);
		else if (errno == ENOENT)
			return (error_message("minishell: no such file or directory: ",
					shell->error_file), false);
		else if (errno == ENOTDIR)
			return (error_message("minishell: not a directory: ",
					shell->error_file), false);
	}
	if (flag_out && access(shell->error_file, W_OK) != 0)
	{
		if (errno == EACCES)
			return (error_message("minishell: permission denied: ",
					shell->error_file), false);
		else if (errno == ENOENT)
			return (error_message("minishell: no such file or directory: ",
					shell->error_file), false);
		else if (errno == ENOTDIR)
			return (error_message("minishell: not a directory: ",
					shell->error_file), false);
	}
	return (true);
}

bool	open_files(t_shell *shell, t_redir_list *file)
{
	t_redir_list	*current;
	int				flag_out;
	int				flag_in;

	current = file;
	flag_out = 0;
	flag_in = 0;
	while (current != NULL)
	{
		if (current->type == RE_INPUT || current->type == HEREDOC)
		{
			if (!open_infile(shell, current, &flag_in, &flag_out))
				return (false);
		}
		else if (current->type == RE_OUTPUT || current->type == APPEND)
			open_outfil(shell, current, &flag_in, &flag_out);
		current = current->next;
	}
	if (shell->error_file)
		if (!check_access(shell, flag_in, flag_out))
			return (false);
	return (true);
}
