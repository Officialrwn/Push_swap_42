/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 13:05:08 by leotran          ###   ########.fr       */
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
	if (op == PA && st->stack_b != NULL)
 		ft_lstadd(&st->stack_a, pop(&st->stack_b));
	if (op == PB && st->stack_a != NULL)
		ft_lstadd(&st->stack_b, pop(&st->stack_a));
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
