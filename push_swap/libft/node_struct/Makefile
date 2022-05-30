# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/05/30 03:16:12 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = libftnode.a
SRC = 	ft_nodeadd_end.c ft_nodeadd_front.c ft_nodedel_front.c ft_nodedel.c ft_nodenew.c ft_nodepop.c ft_nodeswap.c ft_nodeprint.c
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all