/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:31:49 by leo               #+#    #+#             */
/*   Updated: 2022/03/21 10:06:04 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	correct_lis()

int	get_lisindex(int **lis, int *num, int size)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 1;
	while (i < size)
	{
		if (num[i] < num[j])
			(*lis)[j] = ft_max((*lis)[j], (*lis)[i] + 1);
		if (++i == j && j + 1 != size)
		{
			i = 0;
			j++;
		}
	}
	max = (*lis)[j];
	i = j;
	while (--j)
	{
		if (max < (*lis)[j])
			i = j;
		max = ft_max(max, (*lis)[j]);
	}
	return (i);
}

