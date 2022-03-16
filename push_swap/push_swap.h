/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 15:07:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define VALID	0
# define ERROR 	1
# define OP_INDEX "00011222333"
# define STACK_A 0x129
# define STACK_B 0x252

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Forbidden header*/
# include <stdio.h>

typedef struct s_struct
{
	t_list	*op_list;
	t_list	*stack_a;
	t_list	*tail_a;
	t_list	*stack_b;
	t_list	*tail_b;
}	t_struct;

/* Temp functions */
void	cpytostackb(t_struct *st, char *argv, size_t len);
void	print_list(t_list *list, t_list *list2);

typedef enum e_op
{
	SA = 0x1,
	SB = 0x2,
	SS = 0x4,
	PA = 0x8,
	PB = 0x10,
	RA = 0x20,
	RB = 0x40,
	RR = 0x80,
	RRA = 0x100,
	RRB = 0x200,
	RRR = 0x400,
}	t_op;

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

void	swap_ab(t_struct *st, t_op op);
void	push_ab(t_struct *st, t_op op);
void	rotate_ab(t_struct *stm, t_op op);
void	reverse_rotate_ab(t_struct *st, t_op op);
void	print_on_exit(t_struct *st, int flag);
void	swap(t_list **stack, t_list **tail);
int		check_if_sorted(t_struct *st);

typedef void		(*t_fptr)(t_struct *st, t_op op);

static const t_fptr	g_execute_op[4] = {
	swap_ab,
	push_ab,
	rotate_ab,
	reverse_rotate_ab,
};

#endif
