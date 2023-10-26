# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 22:12:51 by andre-da          #+#    #+#              #
#    Updated: 2023/10/26 23:06:49 by andrealbuqu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
