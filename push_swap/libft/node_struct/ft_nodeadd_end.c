/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:24:25 by leotran           #+#    #+#             */
/*   Updated: 2022/03/21 15:56:41 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	ft_nodeadd_end(t_node **tail, t_node *node)
{
	(*tail)->next = node;
	node->prev = (*tail);
	node->next = NULL;
	(*tail) = node;
}
