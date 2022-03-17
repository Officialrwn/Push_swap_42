/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:12:47 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 23:30:46 by leo              ###   ########.fr       */
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
	//ft_lstdel(&st->stack_a, &ft_del_lst_content);
	//ft_lstdel(&st->stack_b, &ft_del_lst_content);
	ft_lstdel(&st->op_list, &ft_del_lst_content);
	exit(flag);
}

void	print_list(t_list *list, t_list *list2)
{
	t_list	*current_node;
	t_list	*temp_node;

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
