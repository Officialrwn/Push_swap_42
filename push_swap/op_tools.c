/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 11:24:58 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ab(t_struct *st, t_op op)
{
	t_list	*temp;

	if (op == PA && st->stack_b != NULL)
	{
		st->a.items[st->a.top + 1] = st->b.items[st->b.top];
		st->a.top++;
		st->b.top--;
	}
	if (op == PB && st->stack_a != NULL)
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		ft_lstadd(&st->stack_b, temp);
	}
}

void	rotate_ab(t_struct *st, t_op op)
{
	int	i;

	if (st->a.top > 0 && (op == RA || op == RR))
	{
		i = st->a.top + 1;
		while (--i > 0)
			ft_swap(&st->a.items[i], &st->a.items[i - 1]);
	}
	if (st->b.top > 0 && (op == RB || op == RR))
	{
		i = st->b.top + 1;
		while (--i > 0)
			ft_swap(&st->b.items[i], &st->b.items[i - 1]);
	}
}

void	reverse_rotate_ab(t_struct *st, t_op op)
{
	int	i;

	if (st->a.top > 0 && (op == RRA || op == RRR))
	{
		i = -1;
		while (++i < st->a.top)
			ft_swap(&st->a.items[i], &st->a.items[i + 1]);
	}
	if (st->b.top > 0 && (op == RRB || op == RRR))
	{
		i = -1;
		while (++i < st->b.top)
			ft_swap(&st->b.items[i], &st->b.items[i + 1]);
	}
}
