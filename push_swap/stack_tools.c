/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:50:37 by leo               #+#    #+#             */
/*   Updated: 2022/03/14 10:28:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_swap(t_list *stack)
{
	t_list	*head;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	head = stack->next;
	stack->next = stack->next->next;
	head->next = stack;
	return (head);
}

t_list	*stack_push(t_list *src, t_list *dest)
{
	t_list	*temp_dest;
	t_list	*temp_src;

	temp = ft_lstnew(src->content, src->content);
}
