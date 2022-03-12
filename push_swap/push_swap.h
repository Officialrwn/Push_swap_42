/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/03/12 20:58:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STDIN 	0
# define A 		1
# define B 		2
# define AB 	3

# define OP_INDEX "00011222333"

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Forbidden header */
# include <stdio.h>

typedef struct s_stack
{
	t_stack *next;
	int		num;
}	t_stack;

typedef struct s_struct
{
	t_stack	*list;
	int		flag;
	int		*stack_a;
	int		*stack_b;
}	t_struct;

void	swap_ab(t_struct *st);
void	push_ab(t_struct *st);
void	rotate_ab(t_struct *st);
void	reverse_rotate_ab(t_struct *st);
void	initialize_struct(t_struct *st, int size);

typedef void		(*t_fptr)(t_struct *st);

static const t_fptr	g_execute_op[4] = {
	swap_ab,
	push_ab,
	rotate_ab,
	reverse_rotate_ab,
};

static const char	*g_op[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr"
};

#endif
