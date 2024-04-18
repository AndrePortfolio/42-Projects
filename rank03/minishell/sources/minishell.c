/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:26:54 by andre-da          #+#    #+#             */
/*   Updated: 2024/04/17 13:26:55 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;

	(void)argv;
	if (argc != 1)
		exit_error_message("Invalid number of arguments", 1);
	signals(MAIN_PROMPT);
	init_shell(&shell, envp);
	exit_info(&shell);
	loop(&shell);
	clean_up(&shell, true);
	return (0);
}
