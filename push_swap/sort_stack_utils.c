/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:12:31 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/13 00:56:40 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	if (!*stack)
		return ;
	biggest = find_max(*stack);
	if ((*stack)->nbr == biggest->nbr)
		ra(stack);
	else if ((*stack)->next->nbr == biggest->nbr)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_medium && cheapest_node->target->above_medium)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_medium) && !(cheapest_node->target->above_medium))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(a, cheapest_node->target, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	min_to_top(t_stack **a)
{
	t_stack	*min_nbr;

	if (!*a)
		return ;
	min_nbr = find_min(*a);
	while ((*a)->nbr != min_nbr->nbr)
	{
		if (min_nbr->above_medium)
			ra(a);
		else
			rra(a);
	}
}
