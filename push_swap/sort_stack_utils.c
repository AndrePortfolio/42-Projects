/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:12:31 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/12 13:16:59 by andrealbuqu      ###   ########.fr       */
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

}

void	move_b_to_a(t_stack **a, t_stack **b)
{

}

void	min_to_top(t_stack **a)
{

}
