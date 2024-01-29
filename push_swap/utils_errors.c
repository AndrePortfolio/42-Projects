/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:42:23 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/13 19:01:10 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if ((str[0] == '+' || str[0] == '-') && str[1] != '\0')
		i++;
	if (str[0] == ' ')
		return (1);
	while (ft_isdigit(str[i]))
		i++;
	if (i >= 1 && str[i] == '\0')
		return (0);
	return (1);
}

int	check_duplicate(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (n == stack->nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!*stack)
		return ;
	current = *stack;
	tmp = NULL;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **stack, char **argv, bool flag)
{
	if (flag)
		ft_free_a_array(argv);
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
