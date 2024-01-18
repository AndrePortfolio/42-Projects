/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:24:01 by andre-da          #+#    #+#             */
/*   Updated: 2023/12/14 17:33:38 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack *a, t_stack *b)
{
	if (!a)
		return ;
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	free_stack(&a);
}

void print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d\n", a->nbr);
		a = a->next;
	}
}

void free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&a, argv);
		free_split(argv);
	}
	else
		init_stack(&a, argv + 1);
	if (!is_sorted(a))
		algo(a, b);
	else
		free_stack(&a);
	return (0);
}
