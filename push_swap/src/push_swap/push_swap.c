/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/09/22 10:11:51 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	init_intarrays(t_struct *st, int size)
{
	st->lis_arr.head = NULL;
	st->lis_arr.tail = NULL;
	st->lis_arr.lis = (int *)malloc(sizeof(int) * size);
	st->lis_arr.num = (int *)malloc(sizeof(int) * size);
	if (!st->lis_arr.num || !st->lis_arr.lis)
		exit (1);
	st->lis_arr.size = size;
	st->lis_arr.mean = 0;
	while (size--)
		st->lis_arr.lis[size] = 1;
}

static int	sort_small_list(t_struct *st, int list_size)
{
	if (list_size > 3)
	{
		push(st, PB, PRINT_ON);
		push(st, PB, PRINT_ON);
	}
	st->max = ft_max(st->stack_a->num, st->stack_a->next->num);
	st->max = ft_max(st->max, st->tail_a->num);
	st->min = ft_min(st->stack_a->num, st->stack_a->next->num);
	st->min = ft_min(st->min, st->tail_a->num);
	while (!check_if_sorted(st))
	{
		if (st->stack_a->num > st->stack_a->next->num
			&& st->stack_a->num > st->tail_a->num)
			rotate(st, RA, PRINT_ON);
		else if (st->stack_a->next->num > st->tail_a->num)
			rotate(st, RRA, PRINT_ON);
		else if (st->stack_a->num > st->stack_a->next->num)
			swap(st, SA, PRINT_ON);
	}
	sort_list(st, list_size);
	print_on_exit(st, VALID, PRINT_OFF);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			*temp;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = init_str_argv(argv[0], &argc);
		initialize_struct(&st);
		init_intarrays(&st, argc - 1);
		temp = st.lis_arr.num;
		while (--argc)
		{
			*temp = validate_argv(&st, *(argv++));
			temp++;
		}
		if (st.lis_arr.size <= 5 && !check_if_sorted(&st))
			return (sort_small_list(&st, st.lis_arr.size));
		get_lis_nums(&st);
		sort_list(&st, st.lis_arr.size);
		print_on_exit(&st, VALID, PRINT_OFF);
	}
	return (0);
}
