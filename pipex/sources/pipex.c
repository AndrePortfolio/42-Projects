/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/27 12:21:33 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	read_input(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_message("Invalid number of arguments");
	(void)argv;
	(void)envp;
}

int main(int argc, char **argv, char **envp)
{
	read_input(argc, argv, envp);
	return (0);
}
