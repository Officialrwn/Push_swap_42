/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/19 15:39:20 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	st;
	int			fd;
	int			ret;
	char		*input;

	fd = 0;
	ret = 1;
	input = NULL;
	if (argc > 1)
	{
		initialize_struct(&st);
		while (--argc > 0)
			validate_argv(&st, argv[argc]);
	}
	return (0);
}
