# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/09/22 11:44:48 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
LIBFT_DIR = libft/
NODE = libft/node_struct/libftnode.a
CHECKER = checker
CHK_SRC = src/checker/checker.c
PUSHSWAP = push_swap
PS_SRC = lis_tools.c push_swap.c sort_tools.c
PS_SRCS = $(addprefix ./src/push_swap/, $(PS_SRC))
COMMON_SRC = print_tools.c stack_tools.c tools.c
COMMON_SRCS = $(addprefix ./src/common/, $(COMMON_SRC))
HEADERS = /includes/
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJECTS = objs
OBJ = *.o

all: $(CHECKER) $(PUSHSWAP)

$(CHECKER):
	@make -C $(LIBFT_DIR)
	@gcc $(FLAGS) $(LIBFT) $(NODE) $(COMMON_SRCS) $(CHK_SRC) -o $(CHECKER)

$(PUSHSWAP):
	@gcc $(FLAGS) $(LIBFT) $(NODE) $(COMMON_SRCS) $(PS_SRCS) -o $(PUSHSWAP)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ) $(SURPL_O)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(CHECKER) $(PUSHSWAP) *.out

re: fclean all