/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:05:34 by leo               #+#    #+#             */
/*   Updated: 2022/09/12 22:51:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

static int	check_push(t_struct st, int a_prev, int a_next, int b)
{
	int	res;

	res = 0;
	if (b > a_prev && b < a_next)
		res = 1;
	if (b > st.max && a_prev == st.max)
		res = 1;
	if (b < a_next && a_prev == st.max && a_next == st.min)
		res = 1;
	return (res);
}

static int	check_from_left(t_struct st, int *a, int *b)
{
	t_node	*temp;
	int		count;
	int		temp_a_count;
	int		min;
	int		a_prev;

	min = 0;
	temp_a_count = 0;
	a_prev = st.tail_a->num;
	while (st.stack_a)
	{
		count = 0 + temp_a_count;
		temp = st.stack_b;
		while (temp)
		{
			if (check_push(st, a_prev, st.stack_a->num, temp->num)
				&& (min > count || min == 0))
			{
				if (count > temp_a_count)
					min = count - temp_a_count;
				else
					min = count;
				*a = st.stack_a->num;
				*b = temp->num;
				break ;
			}
			count++;
			temp = temp->next;
		}
		a_prev = st.stack_a->num;
		st.stack_a = st.stack_a->next;
		temp_a_count++;
	}
	return (min);
}

void	sort_list(t_struct *st, int list_size)
{
	t_op	op;
	int		a;
	int		b;
	int		res;

	a = st->stack_a->num;
	if (st->stack_b)
	{
		b = st->stack_b->num;
		res = check_from_left(*st, &a, &b);
		while (1)
		{
			if (st->stack_a->num == a && st->stack_b->num == b)
				break ;
			if (st->stack_a->num == a)
				rotate(st, RB, PRINT_ON);
			else if (st->stack_b->num == b)
				rotate(st, RA, PRINT_ON);
			else
				rotate(st, RR, PRINT_ON);
		}
		check_push_conditions(st);
		push(st, PA, PRINT_ON);
		sort_list(st, list_size);
	}
	op = find_optimal_correction(st, list_size);
	while (!check_if_sorted(st))
		rotate(st, op, PRINT_ON);
}
