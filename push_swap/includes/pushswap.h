/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/08/02 04:44:35 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define VALID	0
# define ERROR 	1
# define PRINT_ON 1
# define PRINT_OFF 0
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
	int		min;
	int		max;
}	t_struct;

typedef enum e_op
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10,
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
void	swap(t_struct *st, t_op op, int flag);
void	push(t_struct *st, t_op op, int flag);
void	rotate(t_struct *st, t_op op, int flag);
void	print_on_exit(t_struct *st, int flag);
void	print_intarr(int *num, int size);
void	print_list(t_struct *st);
void	get_lis_nums(t_struct *st, t_nums *arr);
void	sort_list(t_struct *st, t_nums *arr);

int		sort_small_list(t_struct *st, int size);
int		validate_argv(t_struct *st, char *argv);
int		check_if_sorted(t_struct *st);
char	**init_str_argv(char *str, int *argc);

typedef void		(*t_fptr)(t_struct *st, t_op op, int flag);

static const t_fptr	g_execute_op[3] = {
	swap,
	push,
	rotate,
};

#endif
