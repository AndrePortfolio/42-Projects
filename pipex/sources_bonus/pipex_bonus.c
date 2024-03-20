/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:56:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/03/20 21:05:35 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	use;
	int		status;

	read_input(argc, argv, &use);
	get_files(&use, argc, argv);
	start_processes(argv, envp, &use);
	close_all_fds(&use);
	status = wait_pids(argc, &use);
	free_all(&use);
	return (WEXITSTATUS(status));
}
