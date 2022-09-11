/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:05:34 by leo               #+#    #+#             */
/*   Updated: 2022/09/11 22:53:11 by leo              ###   ########.fr       */
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

static int	check_push(int a_prev, int a_next, int b, int a_max, int a_min)
{
	int res;
	
	res = 0;
	if (b > a_prev && b < a_next)
		res = 1;
	if (b > a_max && a_prev == a_max)
		res = 1;
	if (b < a_next && a_prev == a_max && a_next == a_min)
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
		// ft_printf("{YEL}stack_a loop current a->num: %d{EOC}\n", st.stack_a->num);
		while (temp)
		{
			// ft_printf("stack_b loop current b->num: %d\nstackmin: %d stackmax: %d min: %d count: %d, ", temp->num, st.min, st.max, min, count);
			// ft_printf("a_prev: %d a->next: %d ", a_prev, st.stack_a->num);
			if (check_push(a_prev, st.stack_a->num, temp->num, st.max, st.min) && (min > count || min == 0))
			{
				if (count > temp_a_count)
					min = count - temp_a_count;
				else
					min = count;
				*a = st.stack_a->num;
				*b = temp->num;
				// ft_printf("checkpush: {GRN}true\n[Steps a: %d b: %d min_count: %d]{EOC}\n", *a, *b, count);
				break ;
			}
			// else
				// ft_printf("checkpush: {RED}false{EOC}\n");
			count++;
			temp = temp->next;
		}
		a_prev = st.stack_a->num;
		st.stack_a = st.stack_a->next;
		temp_a_count++;
	}
	// ft_printf("target a: %d b: %d\n", *a, *b);
	return (min);
}

void	sort_list2(t_struct *st, int list_size)
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
		// print_list("Current stack", st);
		// ft_printf("stack min: %d stack max: %d\n", st->min, st->max);
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
		// print_list("after push:", st);
		sort_list2(st, list_size);
	}
	// print_list("after sort:", st);
	// exit(1);
	op = find_optimal_correction(st, list_size);
	while (!check_if_sorted(st))
		rotate(st, op, PRINT_ON);
	// print_list("after sort:", st);
}