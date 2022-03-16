/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 23:36:23 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct *st, t_op op)
{
	t_list	**stack;
	t_list	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if ((convert_to_bits(op) & STACK_A) == 0)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	ft_lstswap(stack);
	if ((*stack) == (*tail))
		(*tail) = (*stack)->next;
}

void	push(t_struct *st, t_op op)
{
	t_list	*temp;

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
