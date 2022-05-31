/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/05/31 19:58:09 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define VALID	0
# define ERROR 	1
# define OP_INDEX "00011222222"
# define STACK_A 0x129
# define STACK_B 0x252
# define STACK_AB 0x484
# define MAXINT 2147483647
# define MININT -2147483648

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/node_struct/node.h"

typedef struct s_nums
{
	t_node	*lis_head;
	t_node	*lis_tail;
	int		*lis;
	int		*num;
	int		size;
	int		mean;
}	t_nums;

typedef struct s_struct
{
	t_list	*op_list;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tail_a;
	t_node	*tail_b;
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

void	rotate_ab(t_struct *stm, t_op op);
void	reverse_rotate_ab(t_struct *st, t_op op);
void	initialize_struct(t_struct *st);
void	swap(t_struct *st, t_op op);
void	push(t_struct *st, t_op op);
void	rotate(t_struct *st, t_op op);
void	execute_op(t_struct *st);
void	print_on_exit(t_struct *st, int flag);
void	print_intarr(int *num, int size);
void	print_list(t_struct *st);

void	get_lis(t_nums *arr);
int		validate_argv(t_struct *st, char *argv);
int		store_op_call(t_list **op_list, int op_enum, int flag);
int		check_if_sorted(t_struct *st);

typedef void		(*t_fptr)(t_struct *st, t_op op);

static const t_fptr	g_execute_op[3] = {
	swap,
	push,
	rotate,
};

#endif
