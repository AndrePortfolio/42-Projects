# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:32:01 by andre-da          #+#    #+#              #
#    Updated: 2023/10/25 17:44:12 by andrealbuqu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		cp libft/libft.a $(NAME)
		cc -c $(FLAGS) $(FILES)
		ar rs $(NAME) $(OBJS)

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
