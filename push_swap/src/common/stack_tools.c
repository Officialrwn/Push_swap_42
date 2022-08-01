/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/08/02 02:57:37 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	print_op(t_op op, int flag)
{
	if (flag)
		ft_printf("%s\n", g_op[op]);
}

void	swap(t_struct *st, t_op op, int flag)
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
	print_op(op, flag);
}

void	push(t_struct *st, t_op op, int flag)
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
	print_op(op, flag);
}

void	rotate(t_struct *st, t_op op, int flag)
{
	int	check_stack_a;
	int	check_stack_b;

	check_stack_a = (st->stack_a && st->stack_a->next);
	check_stack_b = (st->stack_b && st->stack_b->next);
	if (check_stack_a && (op == RA || op == RR))
		ft_nodeadd_end(&st->tail_a, ft_nodepop(&st->stack_a));
	if (check_stack_b && (op == RB || op == RR))
		ft_nodeadd_end(&st->tail_b, ft_nodepop(&st->stack_b));
	if (check_stack_a && (op == RRA || op == RRR))
	{
		st->tail_a = st->tail_a->prev;
		ft_nodeadd_front(&st->stack_a, st->tail_a->next);
		st->tail_a->next = NULL;
	}
	if (check_stack_b && (op == RRB || op == RRR))
	{
		st->tail_b = st->tail_b->prev;
		ft_nodeadd_front(&st->stack_b, st->tail_b->next);
		st->tail_b->next = NULL;
	}
	print_op(op, flag);
}
