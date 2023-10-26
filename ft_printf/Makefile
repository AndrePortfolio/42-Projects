# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 22:12:51 by andre-da          #+#    #+#              #
#    Updated: 2023/10/26 22:12:52 by andre-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		cc -c $(FLAGS) $(FILES)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
