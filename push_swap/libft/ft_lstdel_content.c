/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:50:25 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 20:24:54 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_content(void *content, size_t contentsize)
{
	if (content != NULL)
	{
		free(content);
		content = NULL;
	}
	contentsize = 0;
}
