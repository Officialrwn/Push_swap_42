/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:05:34 by leo               #+#    #+#             */
/*   Updated: 2022/08/21 17:39:45 by leo              ###   ########.fr       */
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
		while (temp)
		{
			if (check_push_conditions(&st))
			{
				min = ft_min(min, count);
				*a = st.stack_a->num;
				*b = temp->num;
				// ft_printf("Steps: %d a: %d b: %d\n", count, *a, *b);
				break ;
			}
			count++;
			temp = temp->next;
		}
		st.stack_a = st.stack_a->next;
	}
	return (min);
}

static void	sort_min_movement(t_struct st, int *a, int *b)
{
	t_op	op;

	op = RRA;
	check_from_left(st, a, b);
		op = RA;
}

void	sort_list2(t_struct *st, int list_size)
{
	t_op	op;
	int		a;
	int		b;

	a = 0;
	b = 0;
	sort_min_movement(*st, &a, &b);
	op = find_optimal_correction(st, list_size);
	while (!check_if_sorted(st) && (!st->stack_b))
		rotate(st, op, PRINT_ON);
}