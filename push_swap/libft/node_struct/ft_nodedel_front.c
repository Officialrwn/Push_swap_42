/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodedel_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:49:58 by leotran           #+#    #+#             */
/*   Updated: 2022/03/21 15:18:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	ft_nodedel_front(t_node **node)
{
	t_node	*current;

	current = (*node);
	(*node) = (*node)->next;
	free(current);
	current = NULL;
	(*node)->size--;
}
