/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:43:46 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/10/20 13:14:01 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new;
}

/* int	main(void)
{
	int		data = 42;
	t_list *new_node = ft_lstnew(&data);
	t_list *my_list = NULL;

	ft_lstadd_back(&my_list, new_node);
	printf("%d\n", *(int *)(my_list->content));
	return (0);
} */
