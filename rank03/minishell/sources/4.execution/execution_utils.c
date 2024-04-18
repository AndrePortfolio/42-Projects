/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:27:18 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 14:52:06 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_full_cmd(t_tree_node *node)
{
	t_args	*current;
	char	**command;
	int		arg_nbr;
	int		i;

	current = node->args;
	arg_nbr = 0;
	while (current != NULL)
	{
		current = current->next;
		arg_nbr++;
	}
	command = (char **)malloc(sizeof(char *) * (arg_nbr + 2));
	if (!command)
		error_message("Memory allocation Failed", NULL);
	command[0] = ft_strdup(node->cmd);
	i = 1;
	current = node->args;
	while (current != NULL)
	{
		command[i++] = ft_strdup(current->arg);
		current = current->next;
	}
	command[i] = NULL;
	return (command);
}

void	redirect_input_output(t_shell *shell, int i, bool last_cmd)
{
	if (shell->infile)
	{
		if (dup2(shell->infile, STDIN_FILENO) == -1)
			error_message("Error setting infile to STDIN", NULL);
	}
	else if (i != 0)
	{
		if (dup2(shell->fd[i][READ_END], STDIN_FILENO) == -1)
			error_message("Error setting pipe read end to STDIN", NULL);
	}
	if (shell->outfile)
	{
		if (dup2(shell->outfile, STDOUT_FILENO) == -1)
			error_message("Error setting outfile to STDOUT", NULL);
	}
	else if (!last_cmd)
	{
		if (dup2(shell->fd[i + 1][WRITE_END], STDOUT_FILENO) == -1)
			error_message("Error setting pipe write end to STDOUT", NULL);
	}
}

void	execute_child(t_shell *shell, t_tree_node *node, int i)
{
	shell->id_exec[i] = TRUE;
	shell->id[i] = fork();
	if (shell->id[i] == -1)
		error_message("Failed to execute fork", NULL);
	if (shell->id[i] == 0)
	{
		signals(CHILD);
		execute_command(shell, node);
	}
	else
		signals(IGN);
}

void	exec(t_shell *shell, char *path, char **cmd)
{
	close_all_fds(shell, true);
	execve(path, cmd, shell->envp);
	ft_freematrix(cmd);
}

void	executable(t_shell *shell, char *path, char **full_cmd, char *cmd)
{
	path = cmd + 2;
	exec(shell, path, full_cmd);
	child_error_msg(shell, "minishell: no such file or directory: ", cmd, 126);
}
