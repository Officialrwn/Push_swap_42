/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/14 22:22:10 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_struct *st, t_op op)
{
	t_list	*temp;

	temp = NULL;
	if (op == SA || op == SS)
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		ft_lstswap(&st->stack_a, temp);
	}	
 	if (op == SB || op == SS)
	{
		temp = st->stack_b;
		st->stack_b = st->stack_b->next;
		ft_lstswap(&st->stack_b, temp);
	}	
}

void	push_ab(t_struct *st, t_op op)
{
	t_list	*temp;

	temp = NULL;
	if (op == PA && st->stack_b != NULL)
	{
		temp = st->stack_b;
		st->stack_b = st->stack_b->next;
		ft_lstadd(&st->stack_a, temp);
	}
	if (op == PB && st->stack_a != NULL)
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		ft_lstadd(&st->stack_b, temp);
	}	
}
// 	ra - shift up all elements of stack a by 1. 
//	The first element becomes the last one.

// 	rb - shift up all elements of stack a by 1. 
//	The first element becomes the last one.

//	rr -	ra + rb

void	rotate_ab(t_struct *st, t_op op)
{
	st->stack_b = NULL;
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
	st->stack_b = NULL;
	if (op == RRA)
		printf("executing reverse_rotate_a\n");
	if (op == RRB)
		printf("executing reverse_rotate_b\n");
	if (op == RRR)
		printf("executing reverse_rotate a + b\n");
}
