/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:59 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:15:00 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_pwd(t_shell *s, t_tree_node *tree)
{
	int	i;

	i = 0;
	while (s->envp[i])
	{
		if (ft_strncmp(s->envp[i], "PWD=", 4) == 0)
		{
			if (s->pwd)
				free(s->pwd);
			s->pwd = ft_substr(s->envp[i], 4, ft_strlen(s->envp[i]) - 4);
		}
		i++;
	}
	if (!s->pwd)
	{
		add_missing_env(s);
		mini_pwd(s, tree);
	}
	ft_putendl_fd(s->pwd, STDOUT_FILENO);
	(void)tree;
	return (EXIT_SUCCESS);
}
