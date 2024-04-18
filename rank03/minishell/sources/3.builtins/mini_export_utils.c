/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:35:24 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 15:23:02 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sort_env(char **envp)
{
	int		i;
	char	*temp;
	int		j;
	int		len;

	if (!envp)
		return ;
	i = 0;
	temp = NULL;
	len = char_arr_len(envp);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strcmp(envp[j], envp[j + 1]) > 0)
			{
				temp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
}

/*
    Checks if a variable exists in the environment as a standalone variable,
    either with an equal sign or without any value assigned.
    Parameters:
        env: Pointer to the array of environment variables.
        var: Variable name to search for in the environment.
*/
int	is_inenvp(char **env, char *var)
{
	int		i;
	size_t	var_len;

	i = 0;
	var_len = ft_strlen(var);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, var_len) == 0
			&& (env[i][var_len] == '=' || env[i][var_len] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

void	add_env(t_shell *s, char *var)
{
	char	**new_envp;
	int		len;
	int		i;

	if (!var || !s->envp)
		return (error_message("add_env error", NULL));
	len = char_arr_len(s->envp);
	new_envp = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_envp)
		return (error_message("add_env malloc", NULL));
	i = 0;
	while (i < len)
	{
		new_envp[i] = s->envp[i];
		i++;
	}
	new_envp[i] = var;
	new_envp [i + 1] = NULL;
	free(s->envp);
	s->envp = new_envp;
}

void	append_env(char **s, char *var, char *value)
{
	char	*current_value;
	char	*append_value;
	char	*new_value;
	char	*new_var;

	current_value = NULL;
	append_value = ft_strdup(ft_strchr(value, '=') + 1);
	if (ft_strchr(*s, '='))
	{
		current_value = ft_strdup(ft_strchr(*s, '=') + 1);
		new_value = ft_strjoin(current_value, append_value);
	}
	else
		new_value = ft_strdup(append_value);
	free(*s);
	new_var = ft_strjoin(var, "=");
	*s = ft_strjoin(new_var, new_value);
	if (current_value != NULL)
		free(current_value);
	free(append_value);
	free(new_value);
	free(new_var);
	free(value);
}
