/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 16:26:30 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_struct *st, t_op op)
{
	if (st->a.top > 0 && (op == SA || op == SS))
		ft_swap(&st->a.items[st->a.top], &st->a.items[st->a.top - 1]);
	if (st->b.top > 0 && (op == SB || op == SS))
		ft_swap(&st->b.items[st->b.top], &st->b.items[st->b.top - 1]);
}

void	push_ab(t_struct *st, t_op op)
{
	if (st->b.top != -1 && op == PA)
	{
		st->a.items[st->a.top + 1] = st->b.items[st->b.top];
		st->a.top++;
		st->b.top--;
	}
	else if (st->a.top != -1 && op == PB)
	{
		st->b.items[st->b.top + 1] = st->a.items[st->a.top];
		st->b.top++;
		st->a.top--;
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
