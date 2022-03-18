/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:12:47 by leo               #+#    #+#             */
/*   Updated: 2022/03/19 00:49:55 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_on_exit(t_struct *st, int flag)
{
	if (flag)
		write(2, "Error\n", 6);
	else if (check_if_sorted(st))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_nodedel(&st->stack_a);
	ft_nodedel(&st->stack_b);
	ft_lstdel(&st->op_list, &ft_del_lst_content);
	exit(flag);
}

void	print_list(t_struct *st)
{
	t_node	*temp;

	temp = st->stack_a;
	ft_putstr("stack a: ");
	while (temp && st->stack_a)
	{
		ft_printf("%d ", temp->num);
		temp = temp->next;
	}
	temp = st->stack_b;
	if (st->tail_a)
		ft_printf(" tail a: %d\n", st->tail_a->num);
	else
		ft_printf("\n");
	ft_putstr("stack b: ");
	while (temp && st->stack_b)
	{
		ft_printf("%d ", temp->num);
		temp = temp->next;
	}
	if (st->tail_b)
		ft_printf(" tail b: %d\n", st->tail_b->num);
	else
		ft_printf("\n");
}
