/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:45:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:45:51 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* go through array of builtins and return function pointer if exists, else NULL
later in execution can be executed with
if (cmd->builtin != NULL)
	cmd->builtin(shell, tree)
*/
int	(*builtin_arr(char *str))(t_shell *s, struct s_tree_node *tree)
{
	static void	*builtins[7][2] = {
	{"echo", mini_echo},
	{"cd", mini_cd},
	{"pwd", mini_pwd},
	{"export", mini_export},
	{"unset", mini_unset},
	{"env", mini_env},
	{"exit", mini_exit}
	};
	int			i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(builtins[i][0], str))
			return (builtins[i][1]);
		i++;
	}
	return (NULL);
}
