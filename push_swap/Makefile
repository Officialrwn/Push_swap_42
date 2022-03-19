# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/03/19 15:48:05 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
LIBFT_DIR = libft/
NODE = libft/node_struct/libftnode.a
CHECKER = checker
CHK_SRC = src/checker/checker.c
PUSHSWAP = push_swap
PS_SRC = src/push_swap/*.c
COMMON_SRC = src/common/*.c
#SRCS = $(addprefix ./src/, $(SRC))
HEADERS = /includes/
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJ = *.o

all: $(CHECKER) $(PUSHSWAP)

$(CHECKER):
	@make -C $(LIBFT_DIR)
	gcc $(FLAGS) $(LIBFT) $(NODE) $(COMMON_SRC) $(CHK_SRC) -o $(CHECKER)

$(PUSHSWAP):
	gcc $(FLAGS) $(LIBFT) $(NODE) $(COMMON_SRC) $(PS_SRC) -o $(PUSHSWAP)
	
#$(SRCS)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ) $(SURPL_O)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(CHECKER) $(PUSHSWAP) *.out

re: fclean all