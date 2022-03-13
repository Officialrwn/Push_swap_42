/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/13 12:51:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	t_list	*current_node;

	current_node = list;
	while (current_node != NULL)
	{
		printf("%s\n", (char *)current_node->content);
		current_node = current_node->next;
	}
}

void	free_heap(t_struct *st)
{
	free(st->stack_a);
	free(st->stack_b);
	ft_lstdel(&st->list, &ft_del_lst_content);
}

void	error_exit(t_struct *st, int flag)
{
	free_heap(st);
	if (!flag)
		write(2, "Error\n", 6);
	else
		write(1, "KO\n", 3);
	exit(1);
}
