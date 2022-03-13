/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/13 14:00:58 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	sa - 	swap the first 2 elements at the top of stack a. 
//	(Do nothing if there is only one or no elements).

//	sb - 	swap the first 2 elements at the top of stack b. 
//	(Do nothing if there is only one or no elements).

//	ss -	sa + sb

void	swap_ab(t_struct *st, t_op op)
{
	if (op == SA)
		ft_swap(&st->stack_a[0], &st->stack_a[1]); 
	else if (op == SB)
		ft_swap(&st->stack_b[0], &st->stack_b[1]); 
	else if (op == SS)
	{
		ft_swap(&st->stack_a[0], &st->stack_a[1]); 
		ft_swap(&st->stack_b[0], &st->stack_b[1]); 
	}
}
//	take the first element at the top of b and put it at the top of a. 
//	Do nothing if b is empty.

//	take the first element at the top of a and put it at the top of b. 
//	Do nothing if a is empty.

void	push_ab(t_struct *st, t_op op)
{
	int	*temp;

	temp = st->stack_a;
	if (op == PA)
		printf("executing swap_a\n");
	if (op == PB)
		printf("executing swap_b\n");
}
// 	ra - shift up all elements of stack a by 1. 
//	The first element becomes the last one.

// 	rb - shift up all elements of stack a by 1. 
//	The first element becomes the last one.

//	rr -	ra + rb

void	rotate_ab(t_struct *st, t_op op)
{
	int	*temp;

	temp = st->stack_a;
	if (op == RA)
		printf("executing rotate_a\n");
	if (op == RB)
		printf("executing rotate_b\n");
	if (op == RR)
		printf("executing rotate a + b\n");
}
// 	rra - shift down all elements of stack a by 1. 
//	The last element becomes the first one.

// 	rrb - shift down all elements of stack a by 1. 
//	The last element becomes the first one.

//	rrr -	rra + rrb

void	reverse_rotate_ab(t_struct *st, t_op op)
{
	int	*temp;

	temp = st->stack_a;
	if (op == RRA)
		printf("executing reverse_rotate_a\n");
	if (op == RRB)
		printf("executing reverse_rotate_b\n");
	if (op == RRR)
		printf("executing reverse_rotate a + b\n");
}
