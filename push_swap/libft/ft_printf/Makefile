# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/03/18 16:08:19 by leotran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = libftprintf.a
SRC = 	char_printf.c flags_printf.c int_printf.c length_tools.c \
		pointers_printf.c ft_printf.c tools.c get_formats.c bonus.c
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all