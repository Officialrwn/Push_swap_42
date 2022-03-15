/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 21:10:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FD 0
# define VALID	0
# define ERROR 	1
# define OP_INDEX "00011222333"

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
}	t_struct;

/* Temp functions */
void	cpytostackb(t_struct *st, char *argv, size_t len);
void	print_list(t_list *list, t_list *list2);

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

void	swap_ab(t_struct *st, t_op op);
void	push_ab(t_struct *st, t_op op);
void	rotate_ab(t_struct *stm, t_op op);
void	reverse_rotate_ab(t_struct *st, t_op op);
void	print_on_exit(t_struct *st, int flag);
int		check_if_sorted(t_struct *st);
//void	push_b(t_struct *st, t_op op);

typedef void		(*t_fptr)(t_struct *st, t_op op);

static const t_fptr	g_execute_op[4] = {
	swap_ab,
	push_ab,
	rotate_ab,
	reverse_rotate_ab,
};

#endif
