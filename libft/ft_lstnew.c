/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:38:16 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/18 22:10:15 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nbr;

	nbr = (t_list *)malloc(sizeof(t_list));
	if (nbr == NULL)
		return (NULL);
	nbr->content = content;
	nbr->next = NULL;
	return (nbr);
}

/* int	main(void)
{
	int	data = 42;

	t_list *new_node = ft_lstnew(&data);
	printf("%d\n", *(int *)(new_node->content));
	free(new_node);
	return (0);
} */
