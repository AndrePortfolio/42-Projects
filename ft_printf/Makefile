# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:32:01 by andre-da          #+#    #+#              #
#    Updated: 2023/10/21 20:06:32 by andre-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c

OBJS = $(FILES:c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		cc -c $(FLAGS) $(FILES)
		ar rs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
