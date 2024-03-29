# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/10/06 14:49:53 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
PUSHSWAP	=	push_swap
LIBFT		=	libft/libft.a
FLAGS		=	-Wall -Wextra -Werror -O3 -I. -Iincludes/

CHK_SRC		=	checker.c
PS_SRC		=	lis_tools.c push_swap.c sort_tools.c
COMMON_SRC	=	print_tools.c stack_tools.c tools.c

LIBFT_DIR	=	libft/
CHK_DIR		=	src/checker/
PS_DIR		=	src/push_swap/
COMMON_DIR	=	src/common/

CHK_SRCS	=	$(addprefix $(CHK_DIR), $(CHK_SRC))
PS_SRCS		=	$(addprefix $(PS_DIR), $(PS_SRC))
COMMON_SRCS	=	$(addprefix $(COMMON_DIR), $(COMMON_SRC))

OBJ_DIR		=	obj/
OBJS		= 	$(CHK_OBJS) $(PS_OBJS) $(COMMON_OBJS)
CHK_OBJS	=	$(patsubst %, $(OBJ_DIR)%, $(CHK_SRC:.c=.o))
PS_OBJS		=	$(patsubst %, $(OBJ_DIR)%, $(PS_SRC:.c=.o))
COMMON_OBJS	=	$(patsubst %, $(OBJ_DIR)%, $(COMMON_SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(CHK_OBJS) $(PS_OBJS) $(COMMON_OBJS)
	@gcc $(FLAGS) $(LIBFT) $(COMMON_OBJS) $(CHK_OBJS) -o $(NAME)
	@gcc $(FLAGS) $(LIBFT) $(COMMON_OBJS) $(PS_OBJS) -o $(PUSHSWAP)
	@printf "Compilation complete.\n"
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(CHK_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<
	@printf "Checker compiled.\n"

$(OBJ_DIR)%.o: $(PS_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<
	@printf "Push_swap compiled.\n"

$(OBJ_DIR)%.o: $(COMMON_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<
	@printf "Common files compiled.\n"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS) $(SURPL_O)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME) $(PUSHSWAP) *.out

re: fclean all