# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/09/22 12:37:26 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = char_printf.c flags_printf.c int_printf.c length_tools.c \
			pointers_printf.c ft_printf.c tools.c get_formats.c bonus.c
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJS = $(addprefix ./obj/, $(SRC:.c=.o))
OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@printf "Printf done.\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all