/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:23:54 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/15 21:04:31 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*count_nbrs()
{
	int	i = 0;
	sleep (5);
	while (i < 1000)
		printf("%d\n", i++);
	return (NULL);
}

int	main(void)
{
	pthread_t	th;

	pthread_create(&th, NULL, &count_nbrs, NULL);
	pthread_join(th, NULL);
	printf("Marta\n");
}
