/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:17:00 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/12/14 17:31:38 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int	lenght;

	if (lst == NULL)
		return (0);
	lenght = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lenght++;
	}
	return (lenght);
}

/* int main(void)
{
	int	data = 42;

	t_list *new_node = ft_lstnew(&data);
	printf("%d\n", ft_lstsize(new_node));
	free(new_node);
	return (0);
} */
