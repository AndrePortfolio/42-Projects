/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:44:42 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/08 17:35:38 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	(*stack)->prev = (*stack)->next;
	if ((*stack)->next->next)
	{
		(*stack)->next = (*stack)->next->next;
		(*stack)->next->next->prev = *stack;
	}
	else
		(*stack)->next = NULL;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
