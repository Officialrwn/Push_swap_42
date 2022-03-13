/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/13 13:25:44 by leo              ###   ########.fr       */
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

int	check_if_sorted(t_struct *st)
{
	int	i;

	i = 0;
	while (i < st->stack_size - 1)
	{
		if (st->stack_a[i] > st->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_on_exit(t_struct *st, int flag)
{
	if (flag)
		write(2, "Error\n", 6);
	else if (check_if_sorted(st))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_heap(st);
	exit(flag);
}
