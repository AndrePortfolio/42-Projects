/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:25:01 by andre-da          #+#    #+#             */
/*   Updated: 2023/12/07 22:45:35 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

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

// Error handling
int		check_syntax(char *str);
int		check_duplicate(t_stack *a, int n);
void	free_stack(t_stack **a);

// Stack initialization
void	init_stack_a(t_stack **a, char **argv);

// Nodes initialization
void	append_node(t_stack **stack, int n);

// Stack utils
t_stack *find_last(t_stack *stack);

// Commands

// Algorithm

#endif
