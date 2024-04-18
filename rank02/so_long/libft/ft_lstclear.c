/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:01:43 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/10/20 22:35:39 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	if (*lst == NULL)
		return ;
	while (curr)
	{
		next = curr->next;
		del(curr->content);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

/* static void	delete_int(void *data)
{
	free(data);
}

int main(void)
{
	t_list *list = NULL;
	int	i = 1;

	while (i <= 5)
	{
		char *str = (char *)malloc(20 * sizeof(char));
		snprintf(str, 20, "Node %d", i);
		ft_lstadd_back(&list, ft_lstnew(str));
		i++;
	}
	printf("List before clearing:\n");
	t_list *current = list;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	ft_lstclear(&list, delete_int);
    printf("\nList after clearing:\n");
	if (list == NULL)
		printf("The list is empty.\n");
	else
		printf("The list is not empty.\n");
	return (0);
} */
