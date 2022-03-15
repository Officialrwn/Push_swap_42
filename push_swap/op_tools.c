/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 10:11:29 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_struct *st, t_op op)
{
	t_list	*temp;
	int		stack_a;
	int		stack_b;

	stack_a = (st->stack_a == NULL || st->stack_a->next == NULL);
	stack_b = (st->stack_b == NULL || st->stack_b->next == NULL);
	if (!stack_a && (op == SA || op == SS))
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		ft_lstswap(&st->stack_a, temp);
	}
	if (!stack_b && (op == SB || op == SS))
	{
		temp = st->stack_b;
		st->stack_b = st->stack_b->next;
		ft_lstswap(&st->stack_b, temp);
	}
}

void	push_ab(t_struct *st, t_op op)
{
	t_list	*temp;

	if (op == PA && st->stack_b != NULL)
	{
		temp = st->stack_b;
		st->stack_b = st->stack_b->next;
		ft_lstadd(&st->stack_a, temp);
	}
	if (op == PB && st->stack_a != NULL)
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		ft_lstadd(&st->stack_b, temp);
	}
}

void	rotate_ab(t_struct *st, t_op op)
{
	t_list	*temp;
	int		stack_a;
	int		stack_b;

	stack_a = (st->stack_a == NULL || st->stack_a->next == NULL);
	stack_b = (st->stack_b == NULL || st->stack_b->next == NULL);
	if (!stack_a && (op == RA || op == RR))
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		temp->next = NULL;
		ft_lstaddend(&st->stack_a, temp);
	}
	if (!stack_b && (op == RB || op == RR))
	{
		temp = st->stack_b;
		st->stack_b = st->stack_b->next;
		temp->next = NULL;
		ft_lstaddend(&st->stack_b, temp);
	}
}

void	reverse_rotate_ab(t_struct *st, t_op op)
{
	t_list	*temp;
	t_list	*end_node;
	int		stack_a;
	int		stack_b;

	stack_a = (st->stack_a == NULL || st->stack_a->next == NULL);
	stack_b = (st->stack_b == NULL || st->stack_b->next == NULL);
	if (!stack_a && (op == RRA || op == RRR))
	{
		temp = st->stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		end_node = temp->next;
		temp->next = NULL;
		ft_lstadd(&st->stack_a, end_node);
	}
	if (!stack_b && (op == RRB || op == RRR))
	{
		temp = st->stack_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		end_node = temp->next;
		temp->next = NULL;
		ft_lstadd(&st->stack_b, end_node);
	}
}
