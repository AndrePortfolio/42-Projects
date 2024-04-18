/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:22:37 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/17 00:00:44 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_info
{
	int	number;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	think_time;
	int	times_to_eat;
}		t_info;


// Parsing
void	read_input(int argc, char **argv, t_info *philo);
bool	is_white_space(char c, char *spaces);
int		ft_atoi(char *str);

// Close program
void	error_message(char *str);

#endif
