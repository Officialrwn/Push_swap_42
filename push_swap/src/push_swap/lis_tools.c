/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:31:49 by leo               #+#    #+#             */
/*   Updated: 2022/03/21 12:56:58 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	correct_lis(t_nums *arr, int max, int size)
{
	while (size >= 0)
	{
		if (arr->lis[size] == max && max > 0)
			max--;
		else
			arr->lis[size] = -1;
		size--;
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
	correct_lis(arr, max, arr->size);
}
