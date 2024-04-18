/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:53:19 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:53:28 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_path(t_shell *shell)
{
	char	*temp;

	temp = ft_strdup(shell->pwd);
	free(shell->oldpwd);
	shell->oldpwd = temp;
	free(shell->pwd);
	shell->pwd = getcwd(NULL, 0);
}

/* gets values of PWD, OLDPWD and HOME from envp */
void	get_env_vars(t_shell *s)
{
	int	i;

	i = 0;
	s->oldpwd = NULL;
	s->pwd = NULL;
	while (s->envp[i])
	{
		if (ft_strncmp(s->envp[i], "PWD=", 4) == 0)
			s->pwd = ft_substr(s->envp[i], 4, ft_strlen(s->envp[i]) - 4);
		else if (ft_strncmp(s->envp[i], "OLDPWD=", 7) == 0)
			s->oldpwd = ft_substr(s->envp[i], 7, ft_strlen(s->envp[i]) - 7);
		i++;
	}
}

char	*find_path_ret(char *str, t_shell *s)
{
	int	i;

	i = 0;
	while (s->envp[i])
	{
		if (!ft_strncmp(s->envp[i], str, ft_strlen(str)))
			return (ft_substr(s->envp[i], ft_strlen(str),
					ft_strlen(s->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}
