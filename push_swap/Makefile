# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/03/19 00:50:53 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
NODE = libft/node_struct/
NAME = a.out
SRC = 	*.c
#SRCS = $(addprefix ./src/, $(SRC))
HEADERS = /includes/
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJ = *.o

all: $(NAME)
	
$(NAME):
	@make -C $(LIBFT)
	gcc $(FLAGS) $(LIBFT)libft.a $(NODE)libftnode.a $(SRC)
#$(SRCS)

clean:
	@make -C $(LIBFT) clean
	rm -rf $(OBJ)
	rm -rf $(SURPL_O)

fclean: clean
	@make -C $(LIBFT) fclean
	rm -rf $(NAME) *.out

re: fclean all