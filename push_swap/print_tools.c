/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:12:47 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 20:25:52 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_on_exit(t_struct *st, int flag)
{
	if (flag)
		write(2, "Error\n", 6);
	//else if (check_if_sorted(st))
	//	write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	//ft_lstdel(&st->stack_a, &ft_lstdel_content);
	//ft_lstdel(&st->stack_b, &ft_lstdel_content);
	ft_lstdel(&st->op_list, &ft_lstdel_content);
	exit(flag);
}

void	print_list(t_dlist *list, t_dlist *list2)
{
	t_dlist	*current_node;
	t_dlist	*temp_node;

	temp_node = list2;
	current_node = list;
	ft_putstr("stack a: ");
	while (current_node != NULL)
	{
		ft_putstr((char *)current_node->content);
		current_node = current_node->next;
	}
	ft_putstr("\nstack b: ");
	while (temp_node != NULL)
	{
		ft_putstr((char *)temp_node->content);
		temp_node = temp_node->next;
	}
	ft_putstr("\n");
}
