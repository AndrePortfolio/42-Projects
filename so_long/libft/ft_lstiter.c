/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:37:09 by andrealbuqu       #+#    #+#             */
/*   Updated: 2023/10/21 15:28:11 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
	{
		return ;
	}
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* static void print_list_content(void *content)
{
	printf("%s\n", (char*)content);
}

int	main(void)
{
	t_list *list = NULL;
	ft_lstadd_front(&list, ft_lstnew("Hello"));
	ft_lstadd_front(&list, ft_lstnew("World"));
	ft_lstadd_front(&list, ft_lstnew("All"));
	ft_lstiter(list, print_list_content);

	return (0);
} */
