/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/05/31 20:21:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

static void	initialize_intarrays(t_nums *arr, int size)
{
	arr->lis_head = NULL;
	arr->lis_tail = NULL;
	arr->lis = (int *)malloc(sizeof(int) * size);
	arr->num = (int  *)malloc(sizeof(int) * size);
	if (!arr->num || !arr->lis)
		exit (1);
	arr->size = size;
	arr->mean = 0;
	while (size--)
		arr->lis[size] = 1;
}

/* static void pushtob(int *left, int *right, t_struct *st)
{
	if (*left <= *right)
	{
		while (*left-- > 0)
			rotate(st, RA);
		ft_printf("RA\n");
	}	
	else
	{
		ft_printf("right: %d\n", *right);
		while (*right-- >= 0)
		{
			rotate(st, RRA);
			// ft_printf("RRA\n");
		}	
	}
	push(st, PB);
} */

static int get_closest_non_lis(t_node *lis)
{
	t_node	*current;
	t_node	*temp;
	int		res;

	current = lis;
	res = 0;
	while (current)
	{
		temp = current;
		if (current->num == 0)
			break ;
		else if (!lis->prev)
			current = current->next;
		else
			current = current->prev;
		res++;
	}
	if (!current && temp->num != 0)
		res = -1;
	return (res);
}

static void	initialize_stacks(t_nums arr, t_struct *st)
{
	int		left;
	int		right;

	while (1)
	{
		left = get_closest_non_lis(arr.lis_head);
		right = get_closest_non_lis(arr.lis_tail) + 1;
		ft_printf("left: %d right: %d\n", left, right);
		break ;
	}
	st->op_list = NULL;
	arr.mean = 0;

}

int	main(int argc, char **argv)
{
	t_struct	st;
	t_nums		arr;

	if (argc > 1)
	{
		initialize_struct(&st);
		initialize_intarrays(&arr, argc - 1);
		while (--argc > 0)
		{
			arr.num[argc - 1] = validate_argv(&st, argv[argc]);
			arr.mean += arr.num[argc - 1];
		}
		get_lis(&arr);
		initialize_stacks(arr, &st);
		// ft_printf("mean: %d\n", mean);
		ft_nodeprint(&arr.lis_head);
		print_list(&st);
	}
	return (0);
}
