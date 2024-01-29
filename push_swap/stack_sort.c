/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:58:08 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/01/19 12:18:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack *a, t_stack *b)
{
	if (!a)
		return ;
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	free_stack(&a);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	a_lenght;

	a_lenght = stack_len(*a);
	if (a_lenght-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (a_lenght-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (a_lenght-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_NAME_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_NAME_b(a, b);
}
