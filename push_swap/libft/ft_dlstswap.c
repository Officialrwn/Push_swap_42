/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:23:06 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 20:42:26 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstswap(t_dlist **list)
{
	t_dlist	*node;

	node = (*list);
	(*list) = (*list)->next;
	node->next = (*list)->next;
	node->previous = (*list);
	(*list)->next->previous = node;
	(*list)->next = node;
	(*list)->previous = NULL;
}
