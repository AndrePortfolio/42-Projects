/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:12:34 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/10/20 00:57:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* int	main(void)
{
	int	data = 42;
	int	data1 = 43;
	int	data2 = 44;
	t_list *head = ft_lstnew(&data);
	t_list *node1 = ft_lstnew(&data1);
	t_list *node2 = ft_lstnew(&data2);

	head->next = node1;
	node1->next = node2;
	node2->next = NULL;
	ft_lstlast(head);
	printf("%d\n", *(int *)(node2->content));
	free(head);
	free(node1);
	free(node2);
} */
