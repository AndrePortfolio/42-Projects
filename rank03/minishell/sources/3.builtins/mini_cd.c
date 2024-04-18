/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:46:02 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 13:53:15 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* with no args: change envp->pwd to envp->home
with a given path: extend path to make it absolute then update pwd and olpwd
if first argument is -: change to pwd to OLDPWD
always needs to change both the "real" working directory of process with chdir
and update the environemtn variables PWD and OLDPWD
*/
void	add_path_to_env(t_shell *s)
{
	char	*new_pwd;
	int		i;

	new_pwd = NULL;
	i = 0;
	while (s->envp[i])
	{
		if (!ft_strncmp(s->envp[i], "PWD=", 4))
		{
			free(s->envp[i]);
			new_pwd = ft_strjoin("PWD=", s->pwd);
			s->envp[i] = new_pwd;
		}
		else if (!ft_strncmp(s->envp[i], "OLDPWD=", 7) && s->oldpwd)
		{
			free(s->envp[i]);
			new_pwd = ft_strjoin("OLDPWD=", s->oldpwd);
			s->envp[i] = new_pwd;
		}
		i++;
	}
}

/* gets the curren value of env str and sets the process directory to it */
int	specific_path(t_shell *s, char *str)
{
	char	*tmp;
	int		ret;

	ret = 1;
	tmp = find_path_ret(str, s);
	if (tmp)
		ret = chdir(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	if (tmp && ft_strcmp(str, "OLDPWD=") == 0)
		ft_putendl_fd(tmp, STDERR_FILENO);
	if (tmp)
		free(tmp);
	return (ret);
}

int	get_ret(t_tree_node *tree, t_shell *s)
{
	int	ret;

	if (!tree->args)
		ret = specific_path(s, "HOME=");
	else if (ft_strncmp(tree->args->arg, "-", ft_strlen(tree->args->arg)) == 0)
		ret = specific_path(s, "OLDPWD=");
	else
	{
		ret = chdir(tree->args->arg);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(tree->args->arg, STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		}
	}
	return (ret);
}

int	mini_cd(t_shell *s, t_tree_node *tree)
{
	int		ret;

	if (!tree || !s)
		return (error_message("mini cd error", NULL), EXIT_FAILURE);
	ret = 0;
	add_missing_env(s);
	if (args_len(tree->args) > 1)
		return (ft_putstr_fd("minishell: cd: too many arguments\n",
				STDERR_FILENO), EXIT_FAILURE);
	ret = get_ret(tree, s);
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(s);
	add_path_to_env(s);
	return (EXIT_SUCCESS);
}
