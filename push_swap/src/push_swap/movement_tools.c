/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:05:34 by leo               #+#    #+#             */
/*   Updated: 2022/08/21 17:20:25 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_push_a_conditions(t_struct *st)
{
	int	res;

	res = 0;
	if (st->stack_a->num < st->stack_b->num
		&& st->stack_a->num > st->tail_b->num)
		res = 1;
	if (st->stack_a->num > st->tail_b->num && st->tail_b->num == st->max)
	{
		res = 1;
		st->max = st->stack_a->num;
	}
	if (st->stack_a->num < st->stack_b->num && st->stack_b->num == st->min)
	{
		res = 1;
		st->min = st->stack_a->num;
	}
	return (res);
}

static int	check_from_left(t_struct st, int *a, int *b)
{
	t_node	*temp;
	int		count;
	int		min;

	min = 0;
	while (st.stack_a)
	{
		count = 0;
		temp = st.stack_b;
		while (temp)
		{
			if (check_push_a_conditions(&st))
			{
				min = ft_min(min, count);
				*a = st.stack_a->num;
				*b = temp->num;
				break ;
			}
			count++;
			temp = temp->next;
		}
		st.stack_a = st.stack_a->next;
	}
	return (min);
}

t_op	get_min_movement(t_struct st, int *a, int *b)
{
	t_op	op;

	op = RRA;
	check_from_left(st, a, b);
		op = RA;
	return (op);
}

