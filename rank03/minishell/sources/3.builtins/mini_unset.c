/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:16:51 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* accepts one argument, remove it in envp
if no args, error message and return */

void	remove_entry_from_envp(char ***envp, int entry_index)
{
	int		len;
	int		i;
	int		j;
	char	**new_envp;

	len = 0;
	i = 0;
	j = 0;
	while ((*envp)[len])
		len++;
	if (entry_index >= len || entry_index < 0)
		return (error_message("remove entry error", NULL));
	new_envp = malloc(sizeof(char *) * len);
	while (i < len)
	{
		if (i == entry_index)
		{
			i++;
			continue ;
		}
		new_envp[j++] = ft_strdup((*envp)[i++]);
	}
	new_envp[j] = NULL;
	ft_freematrix(*envp);
	*envp = new_envp;
}

int	mini_unset(t_shell *s, t_tree_node *tree)
{
	int		i;
	t_args	*current;

	if (!tree->args)
		return (EXIT_SUCCESS);
	current = tree->args;
	while (current)
	{
		i = 0;
		while (s->envp[i])
		{
			if (ft_strequ(s->envp[i], current->arg))
			{
				remove_entry_from_envp(&(s->envp), i);
				continue ;
			}
			i++;
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
