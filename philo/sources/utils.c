/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:59:06 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/17 00:38:38 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	read_input(int argc, char **argv, t_info *philo)
{
	if (argc != 5 && argc != 6)
		error_message("Invalid number of arguments");
	if (ft_atoi(argv[1]) < 1)
		error_message("Invalid number of philosophers");
	if (ft_atoi(argv[2]) < 1)
		error_message("Invalid death timer");
	if (ft_atoi(argv[3]) < 1)
		error_message("Invalid eat timer");
	if (ft_atoi(argv[4]) < 1)
		error_message("Invalid sleep timer");
	philo->number = ft_atoi(argv[1]);
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 1)
			error_message("Invalid number for times to eat");
		philo->times_to_eat = ft_atoi(argv[5]);
	}
	else
		philo->times_to_eat = -1;
	philo->think_time = (philo->die_time - philo->eat_time - philo->sleep_time) / 4;
	if (philo->think_time < 0)
		philo->think_time = 0;
}

bool	is_white_space(char c, char *spaces)
{
	int	i;

	i = 0;
	while (spaces[i])
	{
		if (spaces[i++] == c)
			return (true);
	}
	return (false);
}

int	ft_atoi(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_white_space(str[i], " \n\v\t\r\f"))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	while (str[i])
	{
		if ((str[i] && !is_white_space(str[i++], " \n\v\t\r\f")))
			error_message("Argument is not a valid number");
	}
	if (result > INT_MAX)
		error_message("Number must be an integer");
	return (result * sign);
}
