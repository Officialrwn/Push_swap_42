/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:42:51 by leo               #+#    #+#             */
/*   Updated: 2022/08/21 20:38:45 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_push_conditions(t_struct *st)
{
	int	res;

	res = 0;
	if (st->stack_b->num < st->stack_a->num
		&& st->stack_b->num > st->tail_a->num)
		res = 1;
	if (st->stack_b->num > st->tail_a->num && st->tail_a->num == st->max)
	{
		res = 1;
		st->max = st->stack_b->num;
	}
	if (st->stack_b->num < st->stack_a->num && st->stack_a->num == st->min)
	{
		res = 1;
		st->min = st->stack_b->num;
	}
	return (res);
}

static t_op	find_optimal_correction(t_struct *st, int list_size)
{
	t_node	*current;
	t_node	*temp;
	t_op	op;
	int		count;

	current = st->stack_a;
	op = RA;
	count = 0;
	while (current)
	{
		temp = current;
		if (current->num == st->max)
			break ;
		current = current->next;
		count++;
	}
	if (count >= list_size / 2)
		op = RRA;
	return (op);
}

static t_op	find_optimal_operation(t_struct *st)
{
	t_op	op;

	if (st->stack_b->num > st->stack_a->num)
		op = RA;
	else
		op = RRA;
	return (op);
}

void	sort_list(t_struct *st, int list_size)
{
	t_op	op;

	while (1)
	{
		if (st->stack_b && check_push_conditions(st))
		{
			push(st, PA, PRINT_ON);
			print_list("after push:", st);
			continue ;
		}
		if (!st->stack_b)
			break ;
		op = find_optimal_operation(st);
		rotate(st, op, PRINT_ON);
		print_list("after rotate:", st);
	}
	op = find_optimal_correction(st, list_size);
	while (!check_if_sorted(st) && (!st->stack_b))
		rotate(st, op, PRINT_ON);
}
