/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:50:05 by leotran           #+#    #+#             */
/*   Updated: 2022/03/18 15:23:12 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*ft_nodenew(int n)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->num = n;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
