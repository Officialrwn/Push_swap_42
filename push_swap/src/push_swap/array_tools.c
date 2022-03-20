/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:31:49 by leo               #+#    #+#             */
/*   Updated: 2022/03/20 14:12:56 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	get_lislen(int **lis, int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (1)
	{
		if (num[i] < num[j])
			(*lis)[j] = ft_max((*lis)[j], (*lis)[i] + 1);
		i++;
		if (j == size - 1 && i == j)
			break ;
		if (i == j)
		{
			i = 0;
			if (j + 1 != size)
				j++;
			continue ;
		}
	}
}
