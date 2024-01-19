/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:09:50 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/01/19 12:01:53 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, char **argv)
{
	int		i;
	long	n;

	i = 0;
	if (!*argv)
		free_errors(stack);
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			free_errors(stack);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack);
		if (check_duplicate(*stack, (int)n))
			free_errors(stack);
		append_node(stack, (int)n);
		i++;
	}
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	last_node = NULL;
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack	*stack)
{
	int	lenght;

	lenght = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		lenght++;
	}
	return (lenght);
}
