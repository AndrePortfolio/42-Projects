/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:25:01 by andre-da          #+#    #+#             */
/*   Updated: 2023/12/11 11:58:17 by andrealbuqu      ###   ########.fr       */
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
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		stack_len(t_stack *stack);
bool	is_sorted(t_stack *stack);

// Commands
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a);
void	pa(t_stack **b);

// Algorithm
void	sort_three(t_stack	**stack);

#endif
