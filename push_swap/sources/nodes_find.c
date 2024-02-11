/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:08:22 by andre-da          #+#    #+#             */
/*   Updated: 2024/01/19 11:20:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_min(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

	min_node = NULL;
	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
			min_node->nbr = stack->nbr;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
