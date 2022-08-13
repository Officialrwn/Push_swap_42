/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/08/13 13:22:27 by leo              ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_struct	st;
	t_nums		arr;
	int			*temp;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = init_str_argv(argv[0], &argc);
		initialize_struct(&st);
		init_intarrays(&arr, argc - 1);
		temp = arr.num;
		while (--argc)
		{
			*temp = validate_argv(&st, *(argv++));
			temp++;
		}
		if (arr.size <= 5)
			return (sort_small_list(&st, arr.size));
		get_lis_nums(&st, &arr);
		sort_list(&st, arr.size);
		// ft_printf("\nSort:\n");
		// print_list(&st);
		print_on_exit(&st, VALID, PRINT_OFF);
	}
	return (0);
}
