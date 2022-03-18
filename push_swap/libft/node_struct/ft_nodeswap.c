/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:13:55 by leotran           #+#    #+#             */
/*   Updated: 2022/03/18 15:18:13 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	ft_nodeswap(t_node **head)
{
	t_node	*node;

	node = (*head);
	(*head) = (*head)->next;
	node->next = (*head)->next;
	node->prev = (*head);
	(*head)->next = node;
	(*head)->prev = NULL;
}
