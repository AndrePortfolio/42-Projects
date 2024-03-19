/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:51:19 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/18 23:56:12 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_input(int argc, char **argv, t_info *use)
{
	int	i;

	check_here_doc(argc, argv, use);
	use->id = malloc(sizeof(pid_t) * use->cmd_nbr);
	if (!(use->id))
		error_message(use, "Memory allocation failed", NULL, 1);
	use->fd = malloc(sizeof(int *) * use->cmd_nbr);
	if (!(use->fd))
		error_message(use, "Memory allocation failed", NULL, 1);
	i = 0;
	while (i < use->cmd_nbr - 1)
	{
		use->fd[i] = malloc(sizeof(int) * 2);
		if (!(use->fd[i]))
			error_message(use, "Memory allocation failed", NULL, 1);
		if (pipe(use->fd[i]) == -1)
			error_message(use, "Failed to create the pipe(s)", NULL, 1);
		i++;
	}
	use->fd[use->cmd_nbr - 1] = NULL;
}

void	check_here_doc(int argc, char **argv, t_info *use)
{
	if (argv[1] && ft_strcmp("here_doc", argv[1]) == 0)
	{
		if (argc < 6)
			error_message2("Invalid number of arguments");
		use->here_doc = true;
		use->cmd_nbr = argc - 4;
	}
	else
	{
		if (argc < 5)
			error_message2("Invalid number of arguments");
		use->here_doc = false;
		use->cmd_nbr = argc - 3;
	}
}
