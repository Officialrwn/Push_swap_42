/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodedel_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:49:58 by leotran           #+#    #+#             */
/*   Updated: 2022/03/18 14:00:27 by leotran          ###   ########.fr       */
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
}
