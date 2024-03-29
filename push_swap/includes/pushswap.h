/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:50 by leo               #+#    #+#             */
/*   Updated: 2022/10/06 14:47:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define VALID	0
# define ERROR 	1
# define PRINT_ON 1
# define PRINT_OFF 0
# define OP_INDEX "000112222223"
# define STACK_A 0x129
# define STACK_B 0x252
# define STACK_AB 0x484
# define MAXINT 2147483647
# define MININT -2147483648

# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "libft/includes/node.h"

typedef struct s_nums
{
	t_node	*head;
	t_node	*tail;
	int		*lis;
	int		*num;
	int		size;
	int		mean;
}	t_nums;

typedef struct s_struct
{
	t_list	*stored_op_list;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tail_a;
	t_node	*tail_b;
	t_nums	lis_arr;
	char	**op_list;
	int		min;
	int		max;
	int		argc;
	char	**argv;
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

void	rotate_ab(t_struct *stm, t_op op);
void	reverse_rotate_ab(t_struct *st, t_op op);
void	initialize_struct(t_struct *st);
void	swap(t_struct *st, t_op op, int print_flag);
void	push(t_struct *st, t_op op, int print_flag);
void	rotate(t_struct *st, t_op op, int print_flag);
void	invalid_op(t_struct *st, t_op op, int print_flag);
void	print_on_exit(t_struct *st, int is_error, int print_flag);
void	get_lis_nums(t_struct *st);
void	sort_list(t_struct *st, int list_size);
void	free_argv(char **argv, int argc);

int		check_push_conditions(t_struct *st);
int		validate_argv(t_struct *st, char *argv);
int		check_if_sorted(t_struct *st);
char	**init_str_argv(t_struct *st, char **argv, int *argc);

#endif
