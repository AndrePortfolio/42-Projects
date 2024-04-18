/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:13:35 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/10/20 22:26:44 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

/* static void delete_int(void *data)
{
	free(data);
}

int main(void)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	int *data = (int *)malloc(sizeof(int));
	*data = 42;
	node->content = data;
	node->next = NULL;

	ft_lstdelone(node, delete_int);
	node = NULL;
	if (node == NULL)
		printf("Node and content deleted successfully.\n");
	else
		printf("Node or content deletion failed.\n");
	return (0);
} */
