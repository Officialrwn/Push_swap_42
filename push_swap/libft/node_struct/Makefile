# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/09/23 10:36:30 by leotran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftnode.a
SRC = 	ft_nodeadd_end.c ft_nodeadd_front.c ft_nodedel_front.c ft_nodedel.c ft_nodenew.c ft_nodepop.c ft_nodeswap.c ft_nodeprint.c
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJS = $(addprefix ./obj/, $(SRC:.c=.o))
OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@printf "Nodestruct done.\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all