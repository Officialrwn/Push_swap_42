/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:31:49 by leo               #+#    #+#             */
/*   Updated: 2022/07/28 06:47:35 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* 
**	Functions to calculate LIS (Longest increasing subsequence) numbers
**	and push non LIS nums to stack b. 
*/

static void	init_lis_stack(t_struct *st, t_nums *arr, int max, int size)
{
	t_node	*temp;
	int		num;

	while (size-- > 0)
	{
		num = 0;
		if (arr->lis[size] == max && max > 0)
		{
			num = max;
			max--;
			st->min = ft_min(st->min, arr->num[size]);
			st->max = ft_max(st->max, arr->num[size]);
		}
		temp = ft_nodenew(num);
		if (!arr->lis_head)
		{
			arr->lis_head = temp;
			arr->lis_tail = temp;
		}	
		else
			ft_nodeadd_front(&arr->lis_head, temp);
	}
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

static void	init_push_non_lis_to_b(t_struct *st, t_nums *arr)
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

void	get_lis_nums(t_struct *st, t_nums *arr)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 1;
	while (i < arr->size)
	{
		if (arr->num[i] < arr->num[j])
			arr->lis[j] = ft_max(arr->lis[j], arr->lis[i] + 1);
		if (++i == j && j + 1 != arr->size)
		{
			i = 0;
			j++;
		}
	}
	max = arr->lis[j];
	while (--j)
		max = ft_max(max, arr->lis[j]);
	init_lis_stack(st, arr, max, arr->size);
	init_push_non_lis_to_b(st, arr);
}
