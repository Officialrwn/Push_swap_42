/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/07/28 07:45:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	init_intarrays(t_nums *arr, int size)
{
	arr->lis_head = NULL;
	arr->lis_tail = NULL;
	arr->lis = (int *)malloc(sizeof(int) * size);
	arr->num = (int *)malloc(sizeof(int) * size);
	if (!arr->num || !arr->lis)
		exit (1);
	arr->size = size;
	arr->mean = 0;
	while (size--)
		arr->lis[size] = 1;
}

static int	check_push_conditions(t_struct *st)
{
	int head_a = st->stack_a->num;
	int head_b = st->stack_b->num;
	int tail_a = st->tail_a->num;
	int	res = 0;
	if (head_b < head_a && head_b > tail_a)
		res = 1;
	if (head_b > tail_a && tail_a == st->max)
	{
		res = 1;
		st->max = head_b;
	}
	if (head_b < head_a && head_a == st->min)
	{
		res = 1;
		st->min = head_b;
	}
	return (res);
}

static void	sort_list(t_struct *st, t_nums *arr)
{
	ft_printf("Sort: \n");
	arr->mean = 0;
	int count = 0;
	while (1)
	{

		if (check_if_sorted(st))
			break ;
		if (st->stack_b && check_push_conditions(st))
		{
			push(st, PA);
			continue;
		}
		if (st->stack_b && st->stack_b->num > st->stack_a->num)
			rotate(st, RA);
		else
			rotate(st, RRA);
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_struct	st;
	t_nums		arr;

	if (argc > 1)
	{
		initialize_struct(&st);
		init_intarrays(&arr, argc - 1);
		while (--argc > 0)
		{
			arr.num[argc - 1] = validate_argv(&st, argv[argc]);
			arr.mean += arr.num[argc - 1];
		}
		arr.mean /= arr.size;
		get_lis_nums(&st, &arr);
		sort_list(&st, &arr);
		print_list(&st);
	}
	return (0);
}
