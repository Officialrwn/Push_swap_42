/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:55 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 19:09:41 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct *st, t_op op)
{
	t_list		**stack;
	t_list		**tail;
	uint16_t	flag;

	stack = &st->stack_a;
	tail = &st->tail_a;
	flag = 0 ^ 1 << op;
	if ((flag & STACK_B) != 0)
	{
		stack = &st->stack_b;
		tail = &st->tail_b;
	}
	ft_lstswap(stack);
	if ((*stack) == (*tail))
		(*tail) = (*stack)->next;
}
