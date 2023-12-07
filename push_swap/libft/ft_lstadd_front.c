/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:47:20 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/20 12:58:27 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	int		data = 42;
	t_list *new_node = ft_lstnew(&data);
	t_list *my_list = NULL;

	ft_lstadd_front(&my_list, new_node);
	printf("%d\n", *(int *)(my_list->content));
	return (0);
} */
