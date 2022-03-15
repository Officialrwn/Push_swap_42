/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 15:46:52 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_struct *st)
{
	int	i;

	i = st->a.top;
	while (i >= 0)
		ft_putnbr(st->a.items[i--]);
	i = st->b.top;
	if (st->b.top != -1)
	{
		ft_putstr("\n");
		while (i >= 0 && st->b.top != -1)
			ft_putnbr(st->b.items[i--]);
	}
	ft_putstr("\n");
}

int	check_if_sorted(t_struct *st)
{
	int	i;

	i = st->a.top;
	if (i == -1)
		return (0);
	while (i > 0)
	{
		if (st->a.items[i] > st->a.items[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	print_on_exit(t_struct *st, int flag)
{
	st->op_list = NULL;
	if (flag)
		write(2, "Error\n", 6);
	else if (check_if_sorted(st))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(flag);
}
