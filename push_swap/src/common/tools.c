/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/19 15:39:44 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	initialize_struct(t_struct *st)
{
	st->op_list = NULL;
	st->stack_a = NULL;
	st->stack_b = NULL;
	st->tail_a = NULL;
	st->tail_b = NULL;
}

void	validate_argv(t_struct *st, char *argv)
{
	t_node	*current_node;
	t_node	*temp;
	int		num;

	current_node = st->stack_a;
	num = ft_atoi(argv);
	if (num == 0 && ft_strcmp(argv, "0") != 0)
		print_on_exit(st, ERROR);
	while (current_node)
	{
		if (current_node->num == num)
			print_on_exit(st, ERROR);
		current_node = current_node->next;
	}
	temp = ft_nodenew(num);
	if (!st->stack_a)
	{
		st->stack_a = temp;
		st->tail_a = temp;
	}
	else
		ft_nodeadd_front(&st->stack_a, temp);
}

int	check_if_sorted(t_struct *st)
{
	t_node	*current;
	int		flag;

	flag = 1;
	current = st->stack_a;
	if (st->stack_a)
	{
		while (current->next)
		{
			if (current->num > current->next->num)
				flag = 0;
			current = current->next;
		}
	}
	return (flag * (!st->stack_b));
}

int	store_op_call(t_list **op_list, int op_enum, int flag)
{
	t_list	*temp;
	char	op_i;

	op_i = OP_INDEX[op_enum];
	temp = ft_lstnew(&op_i, 1);
	temp->content_size = (size_t)op_enum;
	if ((*op_list) == NULL)
		(*op_list) = temp;
	else
		ft_lstaddend(op_list, temp);
	if (flag)
		return (store_op_call(op_list, op_enum + 1, 0));
	return (1);
}

void	execute_op(t_struct *st)
{
	t_list	*current_node;
	t_op	op;
	char	*temp;
	int		i;

	current_node = st->op_list;
	while (current_node != NULL)
	{
		op = current_node->content_size;
		temp = (char *)current_node->content;
		i = temp[0] - '0';
		g_execute_op[i](st, op);
		current_node = current_node->next;
	}
	print_list(st);
	print_on_exit(st, VALID);
}
