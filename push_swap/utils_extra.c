/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:52:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/12 13:40:00 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	if (!stack)
		return ;
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
	
}

void	set_cheapest(t_stack *stack)
{

}

t_stack	*get_cheapest(t_stack *stack)
{

}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{

}
