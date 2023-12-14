/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:31:26 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/14 17:35:07 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stack_len(t_stack	*stack)
{
	int	lenght;

	lenght = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		lenght++;
	}
	return (lenght);
}
