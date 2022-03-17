/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 11:48:15 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define VALID	0
# define ERROR 	1
# define OP_INDEX "00011222333"
# define STACK_A 0x129
# define STACK_B 0x252
# define STACK_AB 0x484

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Forbidden header*/
# include <stdio.h>

typedef struct s_struct
{
	t_list	*op_list;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tail_a;
	t_list	*tail_b;
}	t_struct;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
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

void	print_list(t_list *list, t_list *list2);
void	rotate_ab(t_struct *stm, t_op op);
void	reverse_rotate_ab(t_struct *st, t_op op);
void	validate_argv(t_struct *st, char *argv);
void	initialize_struct(t_struct *st);
void	print_on_exit(t_struct *st, int flag);
void	swap(t_struct *st, t_op op);
void	push(t_struct *st, t_op op);

int		check_if_sorted(t_struct *st);

typedef void		(*t_fptr)(t_struct *st, t_op op);

static const t_fptr	g_execute_op[4] = {
	swap,
	push,
	rotate_ab,
	reverse_rotate_ab,
};

#endif
