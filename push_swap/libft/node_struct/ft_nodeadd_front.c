/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:18:45 by leotran           #+#    #+#             */
/*   Updated: 2022/09/12 22:36:54 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	ft_nodeadd_front(t_node **head, t_node *node)
{
	node->next = (*head);
	node->prev = NULL;
	(*head)->prev = node;
	(*head) = node;
}
