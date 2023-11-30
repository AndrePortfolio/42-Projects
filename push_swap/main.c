/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:24:01 by andre-da          #+#    #+#             */
/*   Updated: 2023/11/30 15:35:01 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char **buffer = NULL;
    stack_t *stack_a = NULL;
    int i = 1;

    if(argc >= 1)
        return (1);
    else if (argc == 2)
        buffer = ft_split(argv[1], ' ');
    else
        buffer = argv;
    stack_a = ft_fillstack(buffer);
}