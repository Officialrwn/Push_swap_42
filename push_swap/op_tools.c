/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 11:32:03 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_struct *st, t_op op)
{
	t_list	*temp;

	if (st->stack_a->next != NULL && (op == SA || op == SS))
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		ft_lstswap(&st->stack_a, temp);
	}	
	if (st->stack_b->next != NULL && (op == SB || op == SS))
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

	if (st->stack_a->next != NULL && (op == RA || op == RR))
	{
		temp = st->stack_a;
		st->stack_a = st->stack_a->next;
		temp->next = NULL;
		ft_lstaddend(&st->stack_a, temp);
	}
	if (st->stack_b->next != NULL && (op == RB || op == RR))
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
	int		stack_b;

	stack_b = (st->stack_b == NULL || st->stack_b->next == NULL);
	if (st->stack_a->next != NULL && (op == RRA || op == RRR))
	{
		temp = st->stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		end_node = temp->next;
		temp->next = NULL;
		ft_lstadd(&st->stack_a, end_node);
	}
	if (op == RRB && !stack_b)
	{
		temp = st->stack_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		end_node = temp->next;
		temp->next = NULL;
		ft_lstadd(&st->stack_b, end_node);
	}
}
