/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/06/12 18:54:41 by leo              ###   ########.fr       */
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

void	sort_list(t_struct *st, t_nums *arr)
{
	// return ;
	// st->op_list = NULL;
	ft_printf("Sort: \n");
	arr->mean = 0;
	int count = 0;
	while (1)
	{
		int head_a = st->stack_a->num, head_b = st->stack_b->num, tail_a = st->tail_a->num;
		if (!st->stack_b || count == 20)
			break ;
		if (head_b < head_a && head_b > tail_a)
			push(st, PA);
		if (head_b > head_a)
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
		get_lis_nums(&arr);
		init_push_non_lis_to_b(&st, &arr);
		sort_list(&st, &arr);
		// ft_nodeprint(&arr.lis_head);
		print_list(&st);
	}
	return (0);
}
