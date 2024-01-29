/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:04:13 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/01/19 12:18:34 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_medium && cheapest->NAME->above_medium)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_medium) && !(cheapest->NAME->above_medium))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->NAME, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->NAME, 'a');
	pa(a, b);
}
