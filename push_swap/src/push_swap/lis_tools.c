/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:31:49 by leo               #+#    #+#             */
/*   Updated: 2022/05/31 22:05:09 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

static void	init_lis_stack(t_nums *arr, int max, int size)
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

void	get_lis(t_nums *arr)
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
	init_lis_stack(arr, max, arr->size);
}
