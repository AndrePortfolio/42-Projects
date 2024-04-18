/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:24:51 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/18 18:59:04 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_message(t_info *use, char *str, char *cmd, int code)
{
	ft_putstr_fd(str, 2);
	if (cmd)
	{
		ft_putendl_fd(cmd, 2);
		free(cmd);
	}
	else
		ft_putchar_fd('\n', 2);
	close_all_fds(use);
	free_all(use);
	exit (code);
}

void	error_message2(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit (1);
}

int	wait_pids(int argc, t_info *use)
{
	int	status;
	int	i;

	i = 0;
	if (use->here_doc)
	{
		while (argc - 5 > 0)
		{
			waitpid(use->id[i++], NULL, 0);
			argc--;
		}
	}
	else
	{
		while (argc - 4 > 0)
		{
			waitpid(use->id[i++], NULL, 0);
			argc--;
		}
	}
	waitpid(use->id[i], &status, 0);
	return (status);
}
