/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:22 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 15:05:03 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_exists(t_shell *s, char *env)
{
	int	i;

	i = 0;
	while (s->envp[i])
	{
		if (!ft_strncmp(s->envp[i], env, ft_strlen(env)))
			return (1);
		i++;
	}
	return (0);
}

void	add_missing_env(t_shell *s)
{
	char	*cwd;

	cwd = NULL;
	if (!env_exists(s, "PWD="))
	{
		cwd = getcwd(NULL, 0);
		add_env(s, ft_strjoin("PWD=", cwd));
		free(cwd);
	}
	if (!env_exists(s, "SHLVL="))
		add_env(s, ft_strdup("SHLVL=0"));
}

void	copy_envp(t_shell *shell, char **envp)
{
	int	len;
	int	i;

	len = 0;
	while (envp[len])
		len++;
	shell->envp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!shell->envp)
		exit_error_message("Envp memory allocation failed", 1);
	i = 0;
	while (i < len)
	{
		shell->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	shell->envp[i] = NULL;
	add_missing_env(shell);
	increase_shlvl(shell);
}

void	init_missing_env(t_shell *shell)
{
	char	path[1024];

	shell->envp = (char **)malloc(sizeof(char *) * 8);
	if (!shell->envp)
		exit_error_message("Envp memory allocation failed", 1);
	if (getcwd(path, sizeof(path)) != NULL)
	{
		shell->envp[0] = ft_strjoin("HOME=", path);
		shell->envp[1] = ft_strjoin("PWD=", path);
		shell->envp[2] = ft_strjoin("OLDPWD=", path);
		shell->envp[3] = ft_strdup("SHLVL=1");
		shell->envp[4] = ft_strdup("_=/usr/bin/env");
		shell->envp[5] = ft_strdup("TERM=xterm-256color");
		shell->envp[6] = NULL;
		increase_shlvl(shell);
	}
}

void	init_shell(t_shell *shell, char **envp)
{
	if (!*envp || !envp)
		init_missing_env(shell);
	else
		copy_envp(shell, envp);
	shell->infile = 0;
	shell->outfile = 0;
	shell->here_doc = 0;
	shell->pipe_nbr = 0;
	shell->status = 0;
	shell->builtins = 0;
	shell->fd = NULL;
	shell->id = NULL;
	shell->id_exec = NULL;
	shell->line = NULL;
	shell->tree = NULL;
	shell->reseted = false;
	shell->tokens = NULL;
	shell->error_file = NULL;
	shell->i = 0;
	shell->std_fds[0] = dup(STDIN_FILENO);
	shell->std_fds[1] = dup(STDOUT_FILENO);
	shell->fds_heredoc[READ_END] = 0;
	shell->fds_heredoc[WRITE_END] = 0;
	get_env_vars(shell);
}
