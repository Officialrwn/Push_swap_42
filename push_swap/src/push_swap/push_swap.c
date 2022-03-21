/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/21 15:24:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	initialize_intarrays(t_nums *arr, int size)
{
	arr->lis = (int *)malloc(sizeof(int) * size);
	arr->num = (int  *)malloc(sizeof(int) * size);
	if (!arr->num || !arr->lis)
		exit (1);
	arr->size = size;
	while (size--)
		arr->lis[size] = 1;
}

static void	initialize_stacks(t_nums arr, t_struct *st, int mean)
{
	t_node	*current;
	int		i;
	int		count;

	current = st->stack_a;
	i = 0;
	count = 0;
	while (i < arr.size)
	{
		if (arr.lis[i++] == -1)
			push(st, PB);
		else
			rotate(st, RA);
		count++;
	}
	ft_printf("count: %d\n", count);
	mean = 0;
}

int	main(int argc, char **argv)
{
	t_struct	st;
	t_nums		arr;
	int			mean;

	if (argc > 1)
	{
		mean = 0;
		initialize_struct(&st);
		initialize_intarrays(&arr, argc - 1);
		while (--argc > 0)
		{
			arr.num[argc - 1] = validate_argv(&st, argv[argc]);
			mean += arr.num[argc - 1];
		}
		get_lis(&arr);
		initialize_stacks(arr, &st, mean);
		//ft_printf("mean: %d\n", mean);
		//print_intarr(arr.lis, arr.size);
		print_list(&st);
	}
	return (0);
}
