/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/21 15:52:48 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap(t_struct *st, t_op op)
{
	t_node	**stack;
	t_node	**tail;

	tail = &st->tail_a;
	stack = &st->stack_a;
	if (op == SB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	if ((*stack) && (*stack)->next)
	{
		ft_nodeswap(stack);
		if ((*stack) == (*tail))
			(*tail) = (*stack)->next;
	}	
}

void	push(t_struct *st, t_op op)
{
	if (op == PA && st->stack_b)
	{
		if (!st->stack_b->next)
			st->tail_b = NULL;
		if (!st->stack_a)
		{
			st->tail_a = st->stack_b;
			st->stack_a = ft_nodepop(&st->stack_b);
		}
		else
			ft_nodeadd_front(&st->stack_a, ft_nodepop(&st->stack_b));
	}
	if (op == PB && st->stack_a)
	{
		if (!st->stack_a->next)
			st->tail_a = NULL;
		if (!st->stack_b)
		{
			st->tail_b = st->stack_a;
			st->stack_b = ft_nodepop(&st->stack_a);
		}
		else
			ft_nodeadd_front(&st->stack_b, ft_nodepop(&st->stack_a));
	}
}

void	rotate(t_struct *st, t_op op)
{
	t_node	**stack;
	t_node	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == RB || op == RRB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	if ((*stack) && (*stack)->next && (op == RA || op == RB))
		ft_nodeadd_end(tail, ft_nodepop(stack));
	else if ((*stack) && (*stack)->next)
	{
		(*tail) = (*tail)->prev;
		ft_nodeadd_front(stack, (*tail)->next);
		(*tail)->next = NULL;
	}
}
