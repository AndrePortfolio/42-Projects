/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:00:58 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/14 17:33:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_NAME_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*NAME_node;
	int		best_match;

	if (!a || !b)
		return ;
	while (a)
	{
		best_match = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				NAME_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == INT_MIN)
			a->NAME = find_max(b);
		else
			a->NAME = NAME_node;
		a = a->next;
	}
}

void	set_NAME_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*NAME_node;
	int		best_match;

	if (!a || !b)
		return ;
	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				NAME_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->NAME = find_min(a);
		else
			b->NAME = NAME_node;
		b = b->next;
	}
}

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
		if (a->NAME->above_medium)
			a->push_cost += a->NAME->index;
		else
			a->push_cost += b_lenght - (a->NAME->index);
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
		stack->cheapest = false;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
