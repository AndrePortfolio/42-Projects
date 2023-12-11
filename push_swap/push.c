/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:19 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/11 11:13:00 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack *tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = tmp;
		dst->prev = NULL;
		dst->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		*dst = tmp;
		(*dst)->prev = NULL;
	}
}

void	pa(t_stack **a)
{
	push(a);
	ft_printf("pa\n");
}

void	pb(t_stack **b)
{
	push(b);
	ft_printf("pb\n");
}
