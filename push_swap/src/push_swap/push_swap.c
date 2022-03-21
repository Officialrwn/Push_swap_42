/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/21 12:55:02 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	initialize_intarrays(t_nums *arr, int size)
{
	arr->lis = (int *)malloc(sizeof(int) * size);
	arr->num = (int *)malloc(sizeof(int) * size);
	if (!arr->num || !arr->lis)
		exit (1);
	arr->size = size;
	while (size--)
		arr->lis[size] = 1;
}

/* static void	initialize_stacks(t_nums arr, t_struct *st)
{
	t_node	*current;
	int		i;

	current = st->stack_a;
	while (i < arr.size)
	{
		if (arr.lis == -1)
		
	}
} */

int	main(int argc, char **argv)
{
	t_struct	st;
	t_nums		arr;

	if (argc > 1)
	{
		initialize_struct(&st);
		initialize_intarrays(&arr, argc - 1);
		while (--argc > 0)
			arr.num[argc - 1] = validate_argv(&st, argv[argc]);
		get_lis(&arr);
		print_intarr(arr.lis, arr.size);
		print_list(&st);
	}
	return (0);
}
