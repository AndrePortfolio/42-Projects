/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:02:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/14 17:03:46 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (!*a || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->NAME)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (!*a || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->NAME)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
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
