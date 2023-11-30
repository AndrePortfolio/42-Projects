/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:50:32 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/30 15:35:01 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    ft_fillstack(char **buffer)
{
    stack_t stack_a = NULL;
    int     i = 1;

    while (!buffer)
    {
        stack_a->nbr = buffer[i++];
        stack_a->next = NULL;
        stack_a->prev = NULL;
    }
    return (stack_a);
}