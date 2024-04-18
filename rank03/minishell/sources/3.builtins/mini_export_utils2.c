/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:36:51 by btoksoez          #+#    #+#             */
/*   Updated: 2024/04/17 14:37:06 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* if append flag, it should find var*/
void	replace_env(t_shell *s, char *var, char *value, int append)
{
	int		i;
	size_t	var_len;

	if (!is_inenvp(s->envp, var))
		return ;
	i = 0;
	var_len = ft_strlen(var);
	while (s->envp[i] != NULL)
	{
		if (ft_strncmp(s->envp[i], var, var_len) == 0)
		{
			if (append)
				append_env(&s->envp[i], var, value);
			else
			{
				free(s->envp[i]);
				s->envp[i] = value;
			}
		}
		i++;
	}
}

char	**copy_env(char **envp)
{
	int		len;
	int		i;
	char	**copy;

	len = char_arr_len(envp);
	copy = (char **)malloc((len + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
		{
			while (i)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[len] = NULL;
	return (copy);
}

/* return 1 & export error if wrong, else 0 */
int	check_var(char *var)
{
	int	i;

	i = 0;
	if (*var == 0)
		return (export_error("="));
	if (ft_isdigit(var[0]))
		return (export_error(var));
	if (var[0] == '=')
		return (export_error(var));
	while (var[i] && var[i] != '=')
	{
		if (check_valid_identifier(var[i]))
			return (export_error(var));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	check_append(char *var, int *flag_append)
{
	int	len;

	len = ft_strlen(var);
	if (len > 0 && var[len - 1] == '+')
	{
		*flag_append = 1;
		var[len - 1] = '\0';
	}
}

void	add_value(t_args *current, int flag_append, char *var, t_shell *s)
{
	char	*new_value;
	char	*new_var;
	char	*value;

	new_value = ft_strdup(ft_strchr(current->arg, '=') + 1);
	new_var = ft_strjoin(var, "=");
	value = ft_strjoin(new_var, new_value);
	free(new_value);
	free(new_var);
	if (is_inenvp(s->envp, var))
		replace_env(s, var, value, flag_append);
	else
		add_env(s, value);
	free(var);
}
