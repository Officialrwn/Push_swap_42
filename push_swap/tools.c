/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/12 16:18:34 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_struct(t_struct *st, int size)
{
	st->flag = 0;
	st->stack_a = (int *)malloc(sizeof(int) * size);
	st->stack_b = (int *)malloc(sizeof(int) * size);
	ft_memset(st->stack_a, 0, size);
	ft_memset(st->stack_b, 0, size);
}
