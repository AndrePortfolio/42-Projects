/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:46:56 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/18 14:52:17 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* static void sample_function(unsigned int index, char *c)
{
    (void)index;
    *c = *c + 1;
}

int	main(void)
{
	char input_string[] = "Hello, World!";

	ft_striteri(input_string, sample_function);
	printf("%s\n", input_string);
	return (0);
} */
