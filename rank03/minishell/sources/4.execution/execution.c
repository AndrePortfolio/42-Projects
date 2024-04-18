/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:27:21 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 14:51:57 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_command(t_shell *shell, t_tree_node *node)
{
	char	**command;
	char	*path;
	int		flag;

	command = NULL;
	path = NULL;
	flag = 1;
	if (node->cmd)
	{
		path = check_path(node->cmd, shell->envp, &flag);
		command = get_full_cmd(node);
	}
	else
	{
		clean_up(shell, false);
		exit (0);
	}
	if (ft_strncmp(node->cmd, "./", 2) == 0)
		executable(shell, path, command, node->cmd);
	if (!path)
		invalid_path(command, shell, node->cmd);
	exec(shell, path, command);
	if (flag)
		free(path);
	child_error_msg(shell, "minishell: command not found: ", node->cmd, 127);
}

void	start_execution(t_shell *s, t_tree_node *node, int i, bool l_cmd)
{
	int	success;

	success = 1;
	s->error_file = NULL;
	if (node->redir_list)
		success = open_files(s, node->redir_list);
	if (success)
	{
		redirect_input_output(s, i, l_cmd);
		if (node->builtin != NULL)
		{
			signals(IGN);
			s->status = node->builtin(s, node);
		}
		else
			execute_child(s, node, i);
	}
	reset_fds(s);
}

void	exec_pipe(t_shell *s, t_tree_node *l_nd, t_tree_node *r_nd, int i)
{
	s->i = i;
	if (i != 0 && s->fd[i - 1])
	{
		if (s->fd[i - 1][READ_END] > 0)
			close(s->fd[i - 1][READ_END]);
		if (s->fd[i - 1][WRITE_END] > 0)
			close(s->fd[i - 1][WRITE_END]);
	}
	if (i != 0)
	{
		s->fd[i + 1] = (int *)malloc(sizeof(int) * 2);
		if (!(s->fd[i + 1]))
			error_message("Fds Memory allocation failed", NULL);
		if (pipe(s->fd[i + 1]) == -1)
			error_message("Failed to create the pipe", NULL);
	}
	start_execution(s, l_nd, i, false);
	if (r_nd->type == PIPE_TREE)
		exec_pipe(s, r_nd->left, r_nd->right, i + 1);
	else
		start_execution(s, r_nd, i + 1, true);
}

void	prepare_to_execute(t_shell *shell)
{
	int	i;

	shell->id = (pid_t *)malloc(sizeof(pid_t) * (shell->pipe_nbr + 2));
	if (!(shell->id))
		error_message("pid_t Memory allocation failed", NULL);
	shell->id_exec = (int *)malloc(sizeof(int) * (shell->pipe_nbr + 2));
	if (!(shell->id_exec))
		error_message("id_exec Memory allocation failed", NULL);
	i = 0;
	while (i < shell->pipe_nbr + 1)
	{
		shell->id_exec[i] = FALSE;
		shell->id[i] = 0;
		i++;
	}
	if (shell->pipe_nbr != 0)
		alloc_pipes(shell);
}

void	execute(t_shell *shell)
{
	prepare_to_execute(shell);
	if (shell->tree->type == PIPE_TREE)
		exec_pipe(shell, shell->tree->left, shell->tree->right, 0);
	else
		start_execution(shell, shell->tree, 0, true);
}
