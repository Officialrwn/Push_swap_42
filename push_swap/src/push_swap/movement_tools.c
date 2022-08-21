/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:05:34 by leo               #+#    #+#             */
/*   Updated: 2022/08/21 20:47:41 by leo              ###   ########.fr       */
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
		ft_printf("stacka\n");
		while (temp)
		{
			ft_printf("temp\n");
			if (check_push_conditions(&st))///not working properly
			{
				min = ft_min(min, count);
				*a = st.stack_a->num;
				*b = temp->num;
				ft_printf("Steps a: %d b: %d\n", *a, *b);
				break ;
			}
			count++;
			temp = temp->next;
		}
		st.stack_a = st.stack_a->next;
	}
	return (min);
}

// static void	sort_min_movement(t_struct st, int *a, int *b)
// {
// 	check_from_left(st, a, b);
// }

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
		// ft_printf("a: %d b: %d\n", a, b);
		// sort_min_movement(*st, &a, &b);
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
		print_list("after push:", st);
		sort_list2(st, list_size);
	}
	// ft_printf("end\n");
	op = find_optimal_correction(st, list_size);
	while (!check_if_sorted(st))
		rotate(st, op, PRINT_ON);
}