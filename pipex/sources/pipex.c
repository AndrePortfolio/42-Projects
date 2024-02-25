/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/25 13:08:41 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	read_input(int argc, char **argv)
{
	if (argc != 5)
		error_message("Invalid number of arguments");
	(void)argv;
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	int	i = 0;
	int j;

	while (envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j])
		{
			write(1, &envp[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
