/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:53:56 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/11 11:58:57 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack	**stack)
{
	t_stack *biggest;

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
