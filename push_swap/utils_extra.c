/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:52:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/14 01:05:45 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_medium = true;
		else
			stack->above_medium = false;
		i++;
		stack = stack->next;
	}
}

void	cost_analysis(t_stack *a, t_stack *b)
{
	int	a_lenght;
	int	b_lenght;

	if (!a || !b)
		return ;
	a_lenght = stack_len(a);
	b_lenght = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_medium))
			a->push_cost = a_lenght - (a->index);
		if (a->target->above_medium)
			a->push_cost += a->target->index;
		else
			a->push_cost += b_lenght - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int		cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	if (!*stack || !top_node)
		return ;
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_medium)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_medium)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
