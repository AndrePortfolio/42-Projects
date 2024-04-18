/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:10 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:00:11 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	only_n(char *str, int *flag)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	*flag = 0;
	return (1);
}

void	put_arg(t_args *current)
{
	ft_putstr_fd(current->arg, 1);
	if (current->next && current->space)
		ft_putchar_fd(' ', 1);
}

/* take all args as input and write to STDOUT (with space in between)
if first arg is -n, then don't write newline */
int	mini_echo(t_shell *shell, t_tree_node *cmd_node)
{
	int		nl_flag;
	t_args	*current;

	if (!cmd_node || !cmd_node->args)
		return (ft_putchar_fd('\n', 1), EXIT_SUCCESS);
	nl_flag = 1;
	current = cmd_node->args;
	while (current && ft_strncmp(current->arg, "-n", 2) == 0)
	{
		if (only_n(current->arg + 1, &nl_flag))
			current = current->next;
		else
			break ;
	}
	while (current)
	{
		put_arg(current);
		current = current->next;
	}
	if (nl_flag)
		ft_putchar_fd('\n', 1);
	shell->status = 0;
	return (EXIT_SUCCESS);
}
