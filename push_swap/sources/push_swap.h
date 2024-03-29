/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:25:01 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/10 12:29:17 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_medium;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Stack initialization
void	init_stack(t_stack **stack, char **argv, bool flag);
void	append_node(t_stack **stack, int n);

// Nodes initialization
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	cost_analysis(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);

// Algorithm
void	algo(t_stack *a, t_stack *b);
void	sort_stacks(t_stack **a, t_stack **b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*get_cheapest(t_stack *stack);
void	min_to_top(t_stack **a);
void	sort_three(t_stack **stack);

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
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// Utils
int		check_syntax(char *str);
int		check_duplicate(t_stack *stack, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack, char **argv, bool flag);
t_stack	*find_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
bool	is_sorted(t_stack *stack);
int		stack_len(t_stack	*stack);

#endif
