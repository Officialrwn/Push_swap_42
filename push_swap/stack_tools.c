/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 22:11:08 by leo              ###   ########.fr       */
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

void	swap(t_struct *st, t_op op)
{
	t_list	**stack;
	t_list	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == SB)
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
	if (op == RB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	(*tail) = pop(stack);
	ft_lstaddend(stack, (*tail));
}

void	reverse_rotate(t_struct *st, t_op op)
{
	t_list	**stack;
	t_list	**tail;
	t_list	*temp;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == RB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	(*tail) = pop(stack);
	ft_lstadd(stack, (*tail));
	temp = (*stack);
	while (temp->next != NULL)
		temp = temp->next;
	(*tail) = temp;
}
