/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 23:04:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*pop(t_list **stack)
{
	t_list	*temp;

	temp = (*stack);
	(*stack) = (*stack)->next;
	return (temp);
}

static t_list	*set_tail_to_prev(t_list **stack)
{
	t_list	*temp;

	temp = (*stack);
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

void	swap(t_struct *st, t_op op)
{
	t_list	**stack;
	t_list	**tail;

	tail = &st->tail_a;
	stack = &st->stack_a;
	if (op == SB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	if ((*stack))
	{
		ft_lstswap(stack);
		if ((*stack) == (*tail))
			(*tail) = (*stack)->next;
	}	
}

void	push(t_struct *st, t_op op)
{
	if (op == PA && st->stack_b)
	{
		if (!st->stack_a)
			st->tail_a = st->stack_b;
		if (!st->stack_b->next)
			st->tail_b = NULL;
		ft_lstadd(&st->stack_a, pop(&st->stack_b));
	}	
	if (op == PB && st->stack_a)
	{
		if (!st->stack_b)
			st->tail_b = st->stack_a;
		if (!st->stack_a->next)
			st->tail_a = NULL;
		ft_lstadd(&st->stack_b, pop(&st->stack_a));
	}
}

void	rotate(t_struct *st, t_op op)
{
	t_list	**stack;
	t_list	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == RB || op == RRB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	if ((*stack) && (op == RA || op == RB))
	{
		(*tail) = pop(stack);
		ft_lstaddend(stack, (*tail));
	}
	else if ((*stack))
	{
		(*tail) = set_tail_to_prev(stack);
		ft_lstadd(stack, (*tail)->next);
		(*tail)->next = NULL;
	}
}
