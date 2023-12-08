/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:42:23 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/07 21:54:37 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '+' || str[i] == '-' && str[1] != '\0')
		i++;
	while (ft_isdigit(str[i]))
			i++;
	if (i >= 1 && str[i] == '\0')
		return (0);
	return (1);
}

int	check_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (n == a->nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!*a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*a = NULL;
	ft_printf("Error\n");
	exit(1);
}
