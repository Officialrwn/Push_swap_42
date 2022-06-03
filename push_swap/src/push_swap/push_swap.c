/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/06/03 22:56:58 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

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

static int	get_closest_non_lis(t_node *lis, int flag)
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
		else if (flag)
			current = current->next;
		else
			current = current->prev;
		res++;
	}
	if (!current && temp->num != 0)
		res = -1;
	return (res);
}

static t_nums	*non_lis_to_stackb(t_struct *st, t_nums *arr, int *n, int flag)
{
	while ((*n)--)
	{
		if (flag)
		{
			rotate(st, RA);
			ft_nodeadd_end(&arr->lis_tail, ft_nodepop(&arr->lis_head));
		}
		else
		{
			rotate(st, RRA);
			arr->lis_tail = arr->lis_tail->prev;
			ft_nodeadd_front(&arr->lis_head, arr->lis_tail->next);
			arr->lis_tail->next = NULL;
		}
	}
	ft_nodedel_front(&arr->lis_head);
	push(st, PB);
	if (st->stack_b->num <= arr->mean)
		rotate(st, RB);
	return (arr);
}

static void	init_stacks(t_nums *arr, t_struct *st)
{
	int	*n;
	int	left;
	int	right;

	while (1)
	{
		n = &left;
		left = get_closest_non_lis(arr->lis_head, 1);
		right = get_closest_non_lis(arr->lis_tail, 0) + 1;
		if (left > right)
			n = &right;
		if (left == -1)
			break ;
		arr = non_lis_to_stackb(st, arr, n, (left < right));
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
		get_lis(&arr);
		init_stacks(&arr, &st);
		ft_nodeprint(&arr.lis_head);
		print_list(&st);
	}
	return (0);
}
