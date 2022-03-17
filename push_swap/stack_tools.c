/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 20:56:06 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlist	*pop(t_dlist **stack)
{
	t_dlist	*temp;

	temp = (*stack);
	(*stack) = (*stack)->next;
	//(*stack)->previous = NULL;
	//temp->next = NULL;
	//temp->previous = NULL;
	return (temp);
}

void	swap(t_struct *st, t_op op)
{
	t_dlist	**stack;
	t_dlist	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == SB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	ft_dlstswap(stack);
	if ((*stack) == (*tail))
		(*tail) = (*stack)->next;
}

void	push(t_struct *st, t_op op)
{
	if (op == PA && st->stack_b != NULL)
		ft_dlstaddfront(&st->stack_a, pop(&st->stack_b));
	if (op == PB && st->stack_a != NULL)
		ft_dlstaddfront(&st->stack_b, pop(&st->stack_a));
}

void	rotate(t_struct *st, t_op op)
{
	t_dlist	**stack;
	t_dlist	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == RB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	(*tail) = pop(stack);
	ft_dlstaddend(stack, (*tail));
}

void	reverse_rotate(t_struct *st, t_op op)
{
	t_dlist	**stack;
	t_dlist	**tail;

	stack = &st->stack_a;
	tail = &st->tail_a;
	if (op == RB)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	(*tail) = (*tail)->previous;
	ft_dlstaddfront(stack, pop(&(*tail)->next));
}
