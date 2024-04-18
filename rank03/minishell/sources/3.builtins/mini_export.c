/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:35:10 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:36:48 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_var(t_shell *s, char *var)
{
	if (!is_inenvp(s->envp, var))
		add_env(s, var);
	else
		free(var);
}

int	add_env_loop(t_shell *s, t_args *current, char *var, int flag_append)
{
	int	return_value;

	return_value = 0;
	while (current)
	{
		var = ft_strdup_delimiter_char(current->arg, '=');
		if (ft_strlen(var) != ft_strlen(current->arg))
			check_append(var, &flag_append);
		if (check_var(var))
		{
			if (current)
				current = current->next;
			return_value = 1;
			free(var);
			continue ;
		}
		if (ft_strlen(var) == ft_strlen(current->arg))
			add_var(s, var);
		else
			add_value(current, flag_append, var, s);
		if (current)
			current = current->next;
	}
	return (return_value);
}

int	mini_export(t_shell *s, t_tree_node *tree)
{
	char	*var;
	char	**copy;
	int		flag_append;
	int		return_value;
	t_args	*current;

	var = NULL;
	flag_append = 0;
	if (!s->envp)
		return (EXIT_FAILURE);
	copy = copy_env(s->envp);
	sort_env(copy);
	if (!tree->args)
		return (print_env(copy), ft_freematrix(copy), EXIT_SUCCESS);
	current = tree->args;
	return_value = add_env_loop(s, current, var, flag_append);
	ft_freematrix(copy);
	return (return_value);
}
