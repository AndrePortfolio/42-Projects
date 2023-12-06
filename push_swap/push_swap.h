/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:25:01 by andre-da          #+#    #+#             */
/*   Updated: 2023/12/06 20:42:08 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	bool			above_medium;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// error handling

// stack initialization
char	**ft_split(char const *s, char c);

// nodes initialization

// utils

// commands

// Algorithm

#endif
