/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:12:47 by leo               #+#    #+#             */
/*   Updated: 2022/03/18 16:13:34 by leotran          ###   ########.fr       */
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
	ft_lstdel(&st->stack_a, &ft_del_lst_content);
	ft_lstdel(&st->stack_b, &ft_del_lst_content);
	ft_lstdel(&st->op_list, &ft_del_lst_content);
	exit(flag);
}

void	print_list(t_struct *st)
{
	t_list	*temp;

	temp = st->stack_a;
	ft_putstr("stack a: ");
	while (temp != NULL && st->stack_a)
	{
		ft_printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	temp = st->stack_b;
	if (st->tail_a)
		ft_printf(" tail a: %s\n", (char *)st->tail_a->content);
	else
		ft_printf("\n");
	ft_putstr("stack b: ");
	while (temp != NULL && st->stack_b)
	{
		ft_printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	if (st->tail_b)
		ft_printf(" tail b: %s\n", (char *)st->tail_b->content);
	else
		ft_printf("\n");
}
