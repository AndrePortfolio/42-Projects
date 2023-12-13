/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:53:56 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/13 00:33:43 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	a_lenght;

	a_lenght = stack_len(a);
	if (!*a || !*b)
		return ;
	if (a_lenght-- > 3 && !is_sorted(a))
		pb(b, a);
	if (a_lenght-- > 3 && !is_sorted(a))
		pb(b, a);
	while (a_lenght-- > 3 && !is_sorted(a))
	{
		init_nodes_a(*a, *b);
		move_a_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (!*a || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->target)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (!*a || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->target)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
