/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 15:18:07 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_struct *st, t_op op)
{
	if (st->a.top != -1 && (op == SA || op == SS))
		ft_swap(&st->a.items[st->a.top], &st->a.items[st->a.top - 1]);
	if (st->b.top != -1 && (op == SB || op == SS))
		ft_swap(&st->b.items[st->b.top], &st->b.items[st->b.top - 1]);
}

void	push_ab(t_struct *st, t_op op)
{
	op = 0;
	st->op_list = NULL;
}

void	rotate_ab(t_struct *st, t_op op)
{
	op = 0;
	st->op_list = NULL;
}

void	reverse_rotate_ab(t_struct *st, t_op op)
{
	op = 0;
	st->op_list = NULL;
}
