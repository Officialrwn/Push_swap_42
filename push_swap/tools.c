/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/14 22:55:06 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list, t_list *list2)
{
	t_list	*current_node;
	t_list	*temp_node;

	temp_node = list2;
	current_node = list;
	while (current_node != NULL)
	{
		printf("%s ", (char *)current_node->content);
		current_node = current_node->next;
	}
	printf("\n");
	while (temp_node != NULL)
	{
		printf("%s ", (char *)temp_node->content);
		temp_node = temp_node->next;
	}
}

int	check_if_sorted(t_struct *st)
{
	t_list	*current_node;
	int		temp;
	int		flag;

	flag = 1;
	current_node = st->stack_a;
	while (current_node->next != NULL)
	{
		temp = ft_atoi(current_node->content);
		if (temp > ft_atoi(current_node->next->content))
			flag = 0;
		current_node = current_node->next;
	}
	if (st->stack_b != NULL)
		flag = 0;
	return (flag);
}

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

void	cpytostackb(t_struct *st, char *argv, size_t len)
{
	t_list	*temp;

	temp = ft_lstnew(argv, len);
	if (st->stack_b == NULL)
		st->stack_b = temp;
	else
		ft_lstaddend(&st->stack_b, temp);
}
