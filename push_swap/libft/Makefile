# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/03/18 16:06:40 by leotran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = libft.a
NODE = node_struct/
PRINTF = ft_printf/
SRC = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
		ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c \
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstaddend.c ft_lstdelend.c \
		ft_lstsize.c ft_dlstnew.c ft_dlstaddfront.c ft_dlstaddend.c ft_dlstdelfront.c ft_countstrings.c \
		ft_strccpy.c ft_get_next_line.c ft_foreach.c ft_uitoa_base.c ft_putaddr.c ft_put_u_nbr.c \
		ft_uint_base_count.c ft_int_base_count.c ft_itoa_base.c ft_float_count.c ft_ftoa.c ft_strjoin_update.c \
		ft_del_lst_content.c ft_swap.c ft_lstswap.c \

SRCS = $(addprefix ./, $(SRC))
FLAGS = -Wall -Wextra -Werror -O3 -I. -Iincludes/
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(NODE)
	@make -C $(PRINTF)
	cp $(NODE)libftnode.a $(NAME)
	cp $(PRINTF)libftprintf.a $(NAME)
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	@make -C $(NODE) clean
	@make -C $(PRINTF) clean
	/bin/rm -f $(OBJ)

fclean: clean
	@make -C $(NODE) fclean
	@make -C $(PRINTF) fclean
	/bin/rm -f $(NAME)

re: fclean all