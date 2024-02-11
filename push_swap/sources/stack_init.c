/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:09:50 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/01/19 12:01:53 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol_upgrd(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) && nbr <= INT_MAX)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	init_stack(t_stack **stack, char **argv, bool flag)
{
	int		i;
	long	n;

	i = 0;
	if (!*argv)
		free_errors(stack, argv, flag);
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			free_errors(stack, argv, flag);
		n = ft_atol_upgrd(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack, argv, flag);
		if (check_duplicate(*stack, (int)n))
			free_errors(stack, argv, flag);
		append_node(stack, (int)n);
		i++;
	}
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	last_node = NULL;
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

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
